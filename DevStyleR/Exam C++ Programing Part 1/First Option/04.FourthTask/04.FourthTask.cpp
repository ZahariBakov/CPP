﻿#include <iostream>

//Task: Даден е двумерен масив А[n][m].Напишете програма която намира броят на
//      елементите с отрицателна стойност, разположени на редове с четни индекси.N, M и
//      елементите на масива се въвеждат от клавиатурата.Резултатът се извежда на екрана.

int main() {
	// инициализиране на променливите
	int n, m;
	int count = 0;

	// въвеждане на размера на редовете
	std::cout << "Enter matrix rows: \n";
	std::cin >> n;

	// въвеждане на размера на колоните
	std::cout << "Enter matrix cols: \n";
	std::cin >> m;

	// създаване на двумерен масив с динамични стойности чрез пойнтър
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[m];
	}

	// въвеждане на числата на двумерния масив
	std::cout << "Enter matrix numbers \n";
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < m; ++col) {
			std::cin >> matrix[row][col];
		}
	}
	std::cout << "\n";

	// обхождане на елементите които са на редове с четни индекси на двумерния масив
	for (int row = 0; row < n; row += 2) {
		for (int col = 0; col < m; ++col) {

			// проверка дали текущото число е по-малко от 0. Не включвам 0.
			if (matrix[row][col] < 0) {
				count ++;

				// принтиране на отрицателните числа
				std::cout << matrix[row][col] << " ";
			}
		}
	}
	std::cout << "\n";

	// извеждане на крайната сума
	std::cout << "The number of negative-values numbers on rows with even indices is: " 
		<< count << std::endl;

    return 0;
}
