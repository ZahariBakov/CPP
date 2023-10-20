#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>

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

void handleFirstTrainEmpty(std::vector<int>& secondTrain,
                           std::list<int>& mergedTrain,
                           std::string& trainSequence) {
    mergedTrain.push_front(secondTrain.back());
    trainSequence.push_back('B');
    secondTrain.pop_back();
}

void handleSecondTrainEmpty(std::vector<int>& firstTrain,
                            std::list<int>& mergedTrain,
                            std::string& trainSequence) {
    mergedTrain.push_front(firstTrain.back());
    trainSequence.push_back('A');
    firstTrain.pop_back();
}

void handleBothTrainsNotEmpty(std::vector<int>& firstTrain,
                              std::vector<int>& secondTrain,
                              std::list<int>& mergedTrain,
                              std::string& trainSequence) {
    if (firstTrain.back() > secondTrain.back()) {
        mergedTrain.push_front(secondTrain.back());
        trainSequence.push_back('B');
        secondTrain.pop_back();
    }
    else {
        mergedTrain.push_front(firstTrain.back());
        trainSequence.push_back('A');
        firstTrain.pop_back();
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
            handleFirstTrainEmpty(secondTrain, mergedTrain, trainSequence);
            continue;
        }

        if (isSecondTrainEmpty) {
            handleSecondTrainEmpty(firstTrain, mergedTrain, trainSequence);
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
