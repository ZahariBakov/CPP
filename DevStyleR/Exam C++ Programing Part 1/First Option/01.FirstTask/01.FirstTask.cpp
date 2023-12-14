#include <iostream>

//Task: Дадено в числото N.Да се напише програма която определя дали N се дели на 5 и
//      3 едновременно.N се въвежда от клавиатурата.Резултатът се извежда на екрана.

int main() {
    // инициализация на променливите
    int number;
    bool isDivisible = false;

    // въвеждане на числото от потребителя 
    std::cout << "Enter number \n";
    std::cin >> number;

    // проверка дали числото се дели на 5 и на 3 и задавана на вярна стойност на булевата
    if (number % 5 == 0 && number % 3 == 0) {
        isDivisible = true;
    }

    // Ако се дели се извежда съобщение
    if (isDivisible) {
        std::cout << "The number is divisible by 5 and by 3.";
    }
    // Ако не се дели се извежда съобщение
    else {
        std::cout << "The number is not divisible by 5 and 3.";
    }

    std::cout << std::endl;

    return 0;
}
