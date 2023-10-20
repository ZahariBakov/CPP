#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>

const char FIRST_TRAIN_MARKET = 'A';
const char SECOND_TRAIN_MARKET = 'B';

std::vector<int> readTrainFromInput() {
    std::vector<int> train;
    std::string line;
    getline(std::cin, line);
    std::istringstream istr(line);
    int currentNumber = 0;

    while (istr >> currentNumber) {
        train.push_back(currentNumber);
    }

    return train;
}

void handleTrain(char trainSymbol,
                 std::vector<int>& train,
                 std::list<int>& mergedTrain,
                 std::string& trainSequence) {
    mergedTrain.push_front(train.back());
    trainSequence.push_back(trainSymbol);
    train.pop_back();
}

void handleBothTrainsNotEmpty(std::vector<int>& firstTrain,
                              std::vector<int>& secondTrain,
                              std::list<int>& mergedTrain,
                              std::string& trainSequence) {
    if (firstTrain.back() > secondTrain.back()) {
        handleTrain(SECOND_TRAIN_MARKET, secondTrain, mergedTrain, trainSequence);
    }
    else {
        handleTrain(FIRST_TRAIN_MARKET, firstTrain, mergedTrain, trainSequence);
    }
}

void mergedTrains(std::vector<int>& firstTrain,
                  std::vector<int>& secondTrain,
                  std::list<int>& mergedTrain,
                  std::string& trainSequence) {
    while (true) {
        const bool isFirstTrainEmpty = firstTrain.empty();
        const bool isSecondTrainEmpty = secondTrain.empty();

        if (isFirstTrainEmpty && isSecondTrainEmpty) {
            break;
        }

        if (isFirstTrainEmpty) {
            handleTrain(SECOND_TRAIN_MARKET, secondTrain, mergedTrain, trainSequence);
            continue;
        }

        if (isSecondTrainEmpty) {
            handleTrain(FIRST_TRAIN_MARKET, firstTrain, mergedTrain, trainSequence);
            continue;
        }
        else {
            handleBothTrainsNotEmpty(firstTrain, secondTrain, mergedTrain, trainSequence);
        }
    }
}

void printSolution(const std::list<int>& mergedTrain,
                   const std::string& trainSequence) {
    std::cout << trainSequence << std::endl;

    for (const int elem: mergedTrain) {
        std::cout << elem << ' ';
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> firstTrain = readTrainFromInput();
    std::vector<int> secondTrain = readTrainFromInput();
    std::list<int> mergedTrain;
    std::string trainSequence;

    mergedTrains(firstTrain, secondTrain, mergedTrain, trainSequence);
    printSolution(mergedTrain, trainSequence);

    return 0;
}
