#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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

    void calculateDistances(const std::vector<Unit>& humans,
                            const std::vector<Zombie>& zombies) {
        // Humans distances
        const size_t humansCount = humans.size();
        mHumanDistances.resize(humansCount);

        for (size_t i = 0; i < humansCount; ++i) {
            const int deltaX = pos.x - humans[i].pos.x;
            const int deltaY = pos.y - humans[i].pos.y;
            const double currDistance = sqrt((deltaX * deltaX) + (deltaY * deltaY));
            mHumanDistances[i] = currDistance;
        }

        // Zombies distances
        const size_t zombiesCount = zombies.size();
        mZombieDistances.resize(zombiesCount);

        for (size_t i = 0; i < zombiesCount; ++i) {
            const int deltaX = pos.x - zombies[i].pos.x;
            const int deltaY = pos.y - zombies[i].pos.y;
            const double currDistance = sqrt((deltaX * deltaX) + (deltaY * deltaY));
            mZombieDistances[i] = currDistance;
        }
    }

    size_t getClosestHumanIdx() {
        return std::min_element(mHumanDistances.begin(), mHumanDistances.end()) - mHumanDistances.begin();
    }                           // This returns an iterator to the smallest Idx - // This retun smallest Idx

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

        if (humansCount == 0 || zombiesCount == 0) {
            mIsRuning = false;
        }
    }

    void calculateDistances() {
        mAsh.calculateDistances(mHumans, mZombies);
    }

    void act() {
        // Find nearset human.
        const size_t clossestHumanIdx = mAsh.getClosestHumanIdx();
        const Unit& clossestHuman = mHumans[clossestHumanIdx];
        std::cout << clossestHuman.pos.x << " " << clossestHuman.pos.y << std::endl;
        
        // This is static coordinates for first solution
        //std::cout << "8000 5000" << std::endl;
    }

    bool isRuning() {
        return mIsRuning;
    }

private:
    Ash mAsh;
    std::vector<Unit> mHumans;
    std::vector<Zombie> mZombies;
    bool mIsRuning = true;
};

int main() {
    Game game;

    while (true) {
        game.readInput();

        if (!game.isRuning()) {
            break;
        }

        game.calculateDistances();
        game.act();
    }


    return 0;
}

// https://www.codingame.com/ide/puzzle/code-vs-zombies