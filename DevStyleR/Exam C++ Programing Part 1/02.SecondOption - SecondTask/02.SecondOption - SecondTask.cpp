﻿#include <iostream>

// Task: Напишете програма която намира броя на всички четирицифрени числа на които
//		 втората и третата цифра са еднакви.Четирицифрените числа са тези в интервала[1000 -
//		 9999].
//		Пример:
//		 Четирицифрени числа с еднакви втора и трета цифра са :
//		 1000 1001 1002 1003 … 9996 9997 9998
//		 Броят е : 899

// Задача 2
int main() {
	// инициализачия на променливата count
	int count = 0;

	// обхождане на числата от 1000 - 9999
	for (int i = 1000; i < 9999; ++i) {

		// проверка дали втората и третат цифра са еднакви
		if ((i / 10) % 10 == (i / 100) % 10) {

			// ако са еднакви се увеличава брояча и се принтира числото
			count++;
			std::cout << i << " ";
		}
	}
	std::cout << "\n";

	// извеждане на общия брой
	std::cout << count << std::endl;

	return 0;
}
