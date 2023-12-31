﻿#include <iostream>

//Task: Напишете програма която намира броя на всички четирицифрени числа на които
//      третата и първата цифра са еднакви.Четирицифрените числа са тези в интервала[1000 -
//      9999].
//    Пример :
//      Четирицифрени числа с еднакви трета и първа цифра са :
//      1010 1011 1012 1013 … 9996 9997 9998
//      Броят е : 899

int main() {
    // инициализиране на променливите
    int count = 0;

    // обхождане на всички числа от 1000 до 9999
    for (int i = 1000; i < 9999; ++i) {

        // проверка дали първта и третата цифри са еднакви
        if ((i % 10) == ((i / 10) % 10)) {

            // ако са еднакви увеличаваме брояча с едно и извеждаме числото
            count++;
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    // принтиране на брояча
    std::cout << count << std::endl;;

    return 0;
}
