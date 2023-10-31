#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <queue>
#include <vector>

const int PLAYER_ONE_IDX = 0;
const int PLAYER_TWO_IDX = 1;
const int PLAYER_COUNT = 2;
const size_t CARDS_FOR_WAR = 3;

bool playSingleTurn(std::array<std::queue<int>, PLAYER_COUNT>& playersDecks,
    std::array<std::queue<int>, PLAYER_COUNT>& playersCards,
    int turnCounter);

int produceCardRank(std::string& card) {
    int cardRank = 0;
    card.pop_back(); //remove card suit
    const char lastLetter = card.back();

    switch(lastLetter) {
    case 'A':
        cardRank = 14;
        break;
    case 'K':
        cardRank = 13;
        break;
    case 'Q':
        cardRank = 12;
        break;
    case 'J':
        cardRank = 11;
        break;
    default:
        cardRank = std::stoi(card);
        break;
    }

    return cardRank;
}

std::vector<std::string> readPlayerCardsFromInput() {
    int numberOfCards = 0;
    std::cin >> numberOfCards;
    std::cin.ignore();

    std::vector<std::string> cards(numberOfCards);

    for (std::string& card : cards) {
        std::cin >> card;
    }

    return cards;
}

std::queue<int> producePlayerDeck() {
    std::queue<int> playerDeck;
    std::vector<std::string> playerCards = readPlayerCardsFromInput();
    int currCardRank = 0;

    for (std::string& card : playerCards) {
        currCardRank = produceCardRank(card);
        playerDeck.push(currCardRank);
    }

    return playerDeck;
}

void printPlayerDeck(std::queue<int> playerDeck) {
    while (!playerDeck.empty()) {
        std::cout << playerDeck.front() << ' ';
        playerDeck.pop();
    }
    std::cout << std::endl;
}

int getOponnetsId(int loserIdx) {
    if (loserIdx == PLAYER_ONE_IDX) {
        return 2;
    }
    
    return 1;
}

void printWinner(int winnerId, int turnCount) {
    std::cout << winnerId << ' ' << turnCount << std::endl;
}

void addCardsToWinner(std::queue<int>& winnerDeck, 
                      std::array<std::queue<int>, PLAYER_COUNT>& playersCards) {
    int currentCard = 0;

    for (int i = 0; i < PLAYER_COUNT; ++i) {
        while (!playersCards[i].empty()) {
            currentCard = playersCards[i].front();
            playersCards[i].pop();
            winnerDeck.push(currentCard);
        }
    }
}

bool playWar(std::array<std::queue<int>, PLAYER_COUNT>& playersDecks,
             std::array<std::queue<int>, PLAYER_COUNT>& playersCards, 
             int turnCounter) {

    bool isGameOver = false;

    for (int i = 0; i < PLAYER_COUNT; ++i) {
        if (CARDS_FOR_WAR > playersDecks[i].size()) {
            std::cout << "PAT" << std::endl;
            isGameOver = true;
            return isGameOver;
        }
    }

    int curentCard = 0;

    for (int i = 0; i < PLAYER_COUNT; ++i) {
        for (size_t card = 0; card < CARDS_FOR_WAR; ++card) {
            curentCard = playersDecks[i].front();
            playersDecks[i].pop();
            playersCards[i].push(curentCard);
        }
    }

    isGameOver = playSingleTurn(playersDecks, playersCards, turnCounter);

    return isGameOver;
}

bool playSingleTurn(std::array<std::queue<int>, PLAYER_COUNT>& playersDecks,
                   std::array<std::queue<int>, PLAYER_COUNT>& playersCards,
                   int turnCounter) {
    bool isGameOver = false;

    for (int i = 0; i < PLAYER_COUNT; ++i) {
        if (playersDecks[i].empty()) {
            printWinner(getOponnetsId(i), turnCounter);
            return true; //game is over
        } 
    }

    const int playerOneCard = playersDecks[PLAYER_ONE_IDX].front();
    playersDecks[PLAYER_ONE_IDX].pop();

    const int playerTwoCard = playersDecks[PLAYER_TWO_IDX].front();
    playersDecks[PLAYER_TWO_IDX].pop();

    playersCards[PLAYER_ONE_IDX].push(playerOneCard);
    playersCards[PLAYER_TWO_IDX].push(playerTwoCard);

    if (playerOneCard > playerTwoCard) {
        addCardsToWinner(playersDecks[PLAYER_ONE_IDX], playersCards);
    }
    else if (playerTwoCard > playerOneCard) {
        addCardsToWinner(playersDecks[PLAYER_TWO_IDX], playersCards);
    }
    else {
        isGameOver = playWar(playersDecks, playersCards, turnCounter);
    }

    return isGameOver;
}

void playGame(std::array<std::queue<int>, PLAYER_COUNT>& playersDecks, 
              std::array<std::queue<int>, PLAYER_COUNT>& playersCards) {
    int turnCounter = 0;
    bool isGameOver = false;

    while (!isGameOver) {
        isGameOver = playSingleTurn(playersDecks, playersCards, turnCounter);
        ++turnCounter;
    }
}

int main() {
    std::array<std::queue<int>, PLAYER_COUNT> playersDecks{
        producePlayerDeck(), producePlayerDeck()
    };

    std::array<std::queue<int>, PLAYER_COUNT> playersCards;

    playGame(playersDecks, playersCards);

    return 0;
}
