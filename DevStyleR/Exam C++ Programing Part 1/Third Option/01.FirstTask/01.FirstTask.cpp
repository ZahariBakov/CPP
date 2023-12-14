#include <iostream>

//Task: Дадено в числото N.Да се напише програма която определя дали N се дели на 9 и
//      11 едновременно.N се въвежда от клавиатурата.Резултатът се извежда на екрана.

int main() {
    // инициализация на променливите
    int number;
    bool isDivisible = false;

    // въвеждане на числото от потребителя 
    std::cout << "Enter number \n";
    std::cin >> number;

    // проверка дали числото се дели на 11 и на 9 и задавана на вярна стойност на булевата
    if (number % 11 == 0 && number % 9 == 0) {
        isDivisible = true;
    }

    // Ако се дели се извежда съобщение
    if (isDivisible) {
        std::cout << "The number is divisible by 11 and by 9.";
    }
    // Ако не се дели се извежда съобщение
    else {
        std::cout << "The number is not divisible by 11 and 9.";
    }

    std::cout << std::endl;

    return 0;
}
