#include <iostream>

//Task: Даден е двумерен масив А[n][m]. Напишете програма която намира
//		произведението на елементите с положителна стойност, разположени на колони с нечетни
//		индекси.N, M и елементите на масива се въвеждат от клавиатурата.Резултатът се извежда
//		на екрана.

// Задача 4
int main() {
	// инициализиране на променливите
	int n, m;
	int sum = 1;

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

	// обхождане на елементите на двумерния масив
	for (int row = 0; row < n; ++row) {
		for (int col = 1; col < m; col += 2) {

			// проверка дали текущото число е по-голямо от 0. Не включвам 0.
			if (matrix[row][col] > 0) {
				sum *= matrix[row][col];

				// принтиране на положителните числа
				std::cout << matrix[row][col] << " ";
			}
		}
	}
	std::cout << "\n";

	// извеждане на крайната сума
	std::cout << sum << std::endl;


	return 0;
}
