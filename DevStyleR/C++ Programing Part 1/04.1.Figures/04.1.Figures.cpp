#include <iostream>

// 01.Pyramid

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//    int star = 1;
//
//    for (int i = 0; i <= number / 2; ++i) {
//
//        for (int j = number / 2; j > i; --j) {
//            std::cout << " ";
//        }
//
//        for (int k = 0; k < star; ++k) {
//            std::cout << "*";
//        }
//        star += 2;
//        std::cout << std::endl;
//    }
//
//    return 0;
//}


// 02.Hourglass

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//    int star = number;
//
//    for (int i = 0; i <= number / 2; ++i) {
//        for (int j = 0; j < i; ++j) {
//            std::cout << " ";
//        }
//
//        for (int k = 0; k < star; ++k) {
//            std::cout << "*";
//        }
//
//        std::cout << std::endl;
//        star -= 2;
//    }
//
//    return 0;
//}


// 03.Diamond

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//    int star = 1;
//
//    for (int i = 0; i <= number / 2; ++i) {
//
//        for (int j = number / 2; j > i; --j) {
//            std::cout << " ";
//        }
//
//        for (int k = 0; k < star; ++k) {
//            std::cout << "*";
//        }
//        star += 2;
//        std::cout << std::endl;
//    }
//
//    star -= 4;
//
//    for (int i = 1; i <= number / 2; ++i) {
//        for (int k = 0; k < i; ++k) {
//            std::cout << " ";
//        }
//
//        for (int j = 0; j < star; ++j) {
//            std::cout << "*";
//        }
//
//        std::cout << std::endl;
//        star -= 2;
//    }
//
//    return 0;
//}


// 04.Cross Pattern

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//
//    for (int i = 0; i < number / 2; ++i) {
//        for (int j = 0; j < number / 2; ++j) {
//            std::cout << " ";
//        }
//
//        std::cout << "*" << std::endl;
//    }
//
//    for (int k = 0; k < number; ++k) {
//        std::cout << "*";
//    }
//
//    std::cout << std::endl;
//
//    for (int i = 0; i < number / 2; ++i) {
//        for (int j = 0; j < number / 2; ++j) {
//            std::cout << " ";
//        }
//
//        std::cout << "*" << std::endl;
//    }
//
//    return 0;
//}


// 05.X Pattern

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//    int freeSpaces = number - 2;
//
//    for (int i = 0; i < number / 2; ++i) {
//        for (int k = 0; k < i; ++k) {
//            std::cout << " ";
//        }
//                
//        std::cout << "*";
//
//        for (int j = 0; j < freeSpaces; ++j) {
//            std::cout << " ";
//        }
//
//        std::cout << "*";
//
//        std::cout << std::endl;
//        freeSpaces -= 2;
//    }
//
//    for (int i = 0; i < number / 2; ++i) {
//        std::cout << " ";
//    }
//
//    std::cout << "*" << std::endl;
//
//    freeSpaces = 1;
//
//    for (int i = 1; i <= number / 2; ++i) {
//        for (int k = number / 2; k > i; --k) {
//            std::cout << " ";
//        }
//
//        std::cout << "*";
//
//        for (int j = 0; j < freeSpaces; ++j) {
//            std::cout << " ";
//        }
//
//        std::cout << "*";
//    
//        std::cout << std::endl;
//        freeSpaces += 2;
//    }    
//
//    return 0;
//}


// 06.Checkerboard

//int main() {
//    int number;
//    std::cout << "Enter number: ";
//    std::cin >> number;
//
//    for (int row = 1; row <= number; ++row) {
//
//        if (row & 1 == 1) {
//            for (int j = 0; j < number; ++j) {
//                std::cout << "* ";
//            }
//        }
//        else {
//            for (int k = 0; k < number; ++k) {
//                std::cout << " *";
//            }
//        }
//
//        std::cout << std::endl;        
//    }
//
//    return 0;
//}


// 07.Number Pattern

int main() {
    int number;
    std::cout << "Enter number: ";
    std::cin >> number;

    for (int i = 1; i <= number; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << i;
        }
        std::cout  << std::endl;
    }

    return 0;
}

