#include <iostream>
#include <vector>

int main() {
    // NOTE: this bracket {} initialization for std::vectors is supported since C++11
    std::vector<std::vector<char> > charMatrix =
    {
        std::vector<char> {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        std::vector<char> {' ', '/', '-', '-', 'V', '-', '-', '\\', ' '},
        std::vector<char> {' ', '\\', ' ', ' ', ' ', ' ', ' ', '/', ' '},
        std::vector<char> {' ', ' ', '\\', ' ', ' ', ' ', '/', ' ', ' '},
        std::vector<char> {' ', ' ', ' ', '\\', ' ', '/', ' ', ' ', ' '},
        std::vector<char> {' ', ' ', ' ', ' ', 'V', ' ', ' ', ' ', ' '},
    // NOTE: having a comma after the last element
    // (1D array in this case) is ok
    };

    for (rsize_t row = 0; row < charMatrix.size(); row++) {
        for (rsize_t col = 0; col < charMatrix[row].size(); col++) {
            std::cout << charMatrix[row][col];
        }
        std::cout << std::endl;
    }

    std::cout << "hearts don't look like that btw" << std::endl;
    std::cout << std::endl;

    std::vector<std::vector<int> > identityMatrix =
    {
        /*std::vector<int> {1, 0, 0},
        std::vector<int> {0, 1, 0},
        std::vector<int> {0, 0, 1}*/

        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            std::cout << identityMatrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<std::vector<std::vector<int> > > cube =
    {
        std::vector<std::vector<int> >
        {
            std::vector<int> {111, 112, 113, 114},
            std::vector<int> {121, 122, 123, 124},
            std::vector<int> {131, 132, 133, 134},
        },
        std::vector<std::vector<int> >
        {
            std::vector<int> {211, 212, 213, 214},
            std::vector<int> {221, 222, 223, 224},
            std::vector<int> {231, 232, 233, 234},
        }
    };

    int inputMatrixRows = 0;
    int inputMatrixCols = 0;

    std::cout << "Enter array rows: ";
    std::cin >> inputMatrixRows;

    std::cout << "Enter array cols: ";
    std::cin >> inputMatrixCols;

    std::vector<std::vector<int> > inputMatrix;

    for (int row = 0; row < inputMatrixRows; row++) {
        std::vector<int> inputRow;

        for (int col = 0; col < inputMatrixCols; col++) {
            int element;
            std::cin >> element;
            inputRow.push_back(element);
        }

        inputMatrix.push_back(inputRow);
    }

    std::cout << "The matrix you typed in:" << std::endl;

    for (int row = 0; row < inputMatrixRows; row++) {
        for (int col = 0; col < inputMatrixCols; col++) {
            std::cout << inputMatrix[row][col] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
