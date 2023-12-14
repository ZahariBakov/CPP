#include <iostream>

//Task: Дадено в числото N. Да се напише програма която определя дали N се дели на 7 и
//		2 едновременно.N се въвежда от клавиатурата.Резултатът се извежда на екрана.

// Задача 1
int main() {
	// инициализация на променлвите
	int n;
	bool isCorrect = false;

	// въввеждане на числото n
	std::cin >> n;

	// проверка дали числото се дели на 7 и 2 без остатък и задаване на стойност на булевата променлива
	if (n % 7 == 0 && n % 2 == 0) {
		isCorrect = true;
	}

	if (isCorrect) {
		std::cout << "The number is divisible by 7 and by 2.";
	}
	else {
		std::cout << "The number is not divisible by 7 and 2.";
	}

	std::cout << std::endl;

	return 0;
}