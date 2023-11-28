#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Point {
    int x;
    int y;
};

struct Unit {
    Point pos;
    int id;
};

struct Zombie: public Unit {
    Point futurePos;
};

class Ash: public Unit {
public:

    void readInput() {
        std::cin >> pos.x >> pos.y;
    }

private:
    std::vector<double> mHumanDistances;
    std::vector<double> mZombieDistances;
};

class Game {
public:

    void readInput() {
        mAsh.readInput();

        size_t humansCount = 0;
        std::cin >> humansCount;
        mHumans.resize(humansCount);

        for (auto& human : mHumans) {
            std::cin >> human.id;
            std::cin >> human.pos.x;
            std::cin >> human.pos.y;
        }

        size_t zombiesCount = 0;
        std::cin >> zombiesCount;
        mZombies.resize(zombiesCount);

        for (auto& zombie : mZombies) {
            std::cin >> zombie.id;
            std::cin >> zombie.pos.x;
            std::cin >> zombie.pos.y;
            std::cin >> zombie.futurePos.x;
            std::cin >> zombie.futurePos.y;
        }
    }

    void calculateDistances() {

    }

    void act() {
        std::cout << "8000 5000" << std::endl;
    }

    bool isRuning() {
        return true;
    }

private:
    Ash mAsh;
    std::vector<Unit> mHumans;
    std::vector<Zombie> mZombies;
};

int main() {
    Game game;

    while (game.isRuning()) {
        game.readInput();
        game.calculateDistances();
        game.act();
    }


    return 0;
}

// https://www.codingame.com/ide/puzzle/code-vs-zombies