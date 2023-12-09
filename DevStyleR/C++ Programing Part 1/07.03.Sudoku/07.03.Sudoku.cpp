#include <iostream>

int main() {

    // Creating array
    int arr[]{ 3,5,2, 4,6,9, 7,8,1,
               6,9,7, 1,8,5, 9,3,2,
               8,9,1, 2,7,3, 6,5,4,
               1,3,9, 6,4,2, 5,7,8,
               4,6,5, 8,4,7, 2,1,3,
               2,7,8, 5,3,1, 4,9,6,
               1,2,4, 5,1,8, 3,6,7,
               5,1,3, 9,2,6, 8,4,7,
               7,8,6, 3,5,4, 1,2,9 };

    // Create table sudoku
    int sudoku[9][9];
    int idx = 0;

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            sudoku[row][col] = arr[idx];
            idx++;
        }
    }

    // Printing sudoku
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            std::cout << sudoku[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    // Checking if Sudoku is correct
    bool isCorrect = true;
    int currColNum = 1;
    int currRowNum = 1;
    int currNum = 0;
    int countRow = 0;
    int countCol = 0;

    for (int row = 0; row < 9; ++row) {
        for (currColNum = 1; currColNum < 10; ++currColNum) {
            for (int col = 0; col < 9; ++col) {
                currNum = sudoku[row][col];

                if (currNum == currColNum) {
                    countCol++;
                }
            }

            if (countCol > 1) {
                std::cout << "The number " << currColNum << " is found " << countCol << " times in column " << row << std::endl;
                isCorrect = false;
            }
        }      
    }

    /*

    if (countRow > 1) {
        std::cout << "The number " << currRowNum << " is found " << countRow << " times in row " << row << std::endl;
        isCorrect = false;
    }*/

    return 0;
}
