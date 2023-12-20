#include <iostream>
#include <array>

#include "BigInt.h"

bool isDivisibleBy5(const BigInt& bigInt) {
    const auto digits = bigInt.getDigits();

    if (digits.empty()) {
        return false;
    }

    const char lastDigit = digits.back();

    if (lastDigit == '0' || lastDigit == '5') {
        return true;
    }

    return false;
}

bool isDivisibleBy9(const BigInt& bigInt) {
    const auto digits = bigInt.getDigits();
    int sum = 0;

    for (const auto digit : digits) {
        sum += (digit - '0');
    }

    if (sum == 0) {
        return false;
    }

    if (sum % 9 == 0) {
        return true;
    }

    return false;
}

bool isDivisibleBy45(const BigInt& bigInt) {
    return isDivisibleBy5(bigInt) && isDivisibleBy9(bigInt);
}

void performUnitTests() {
    // Create objects
    BigInt six("6");
    BigInt five("5");
    BigInt zero("0");
    BigInt nine("9");
    BigInt num("126");

    // Is divisible by 5
    std::cout << "Divisible by 5: \n";
    std::cout << "Is 6 divisibleBy5: " << std::boolalpha << isDivisibleBy5(six) << std::endl;
    std::cout << "Is 5 divisibleBy5: " << std::boolalpha << isDivisibleBy5(five) << std::endl;
    std::cout << "Is 0 divisibleBy5: " << std::boolalpha << isDivisibleBy5(zero) << std::endl;
    std::cout << "Is 9 divisibleBy5: " << std::boolalpha << isDivisibleBy5(nine) << std::endl;
    std::cout << "Is 123 divisibleBy5: " << std::boolalpha << isDivisibleBy5(num) << "\n" << std::endl;

    // Is divisibke by 9
    std::cout << "Divisible by 9: \n";
    std::cout << "Is 6 divisibleBy9: " << std::boolalpha << isDivisibleBy9(six) << std::endl;   
    std::cout << "Is 5 divisibleBy9: " << std::boolalpha << isDivisibleBy9(five) << std::endl;
    std::cout << "Is 0 divisibleBy9: " << std::boolalpha << isDivisibleBy9(zero) << std::endl;
    std::cout << "Is 9 divisibleBy9: " << std::boolalpha << isDivisibleBy9(nine) << std::endl; 
    std::cout << "Is 126 divisibleBy9: " << std::boolalpha << isDivisibleBy9(num) << std::endl;
}

constexpr auto ARRAY_SIZE = 2;

std::array<BigInt, ARRAY_SIZE> readInput() {
    std::array<std::string, ARRAY_SIZE> stringInput;
    //std::cin >> stringInput[0] >> stringInput[1];

    for (auto& elem : stringInput) {
        std::cin >> elem;
    }

    std::array<BigInt, ARRAY_SIZE> arr{ stringInput[0], stringInput[1] };

    return arr;
}

int main() {
    const auto numbers = readInput();
    const auto& start = numbers[0];
    const auto& end = numbers[1];
    const BigInt ONE(1);
    const BigInt FIVE(5);
    const BigInt FOURTY_FIVE(45);
    auto currNum = start;

    for (currNum; currNum < end; currNum += ONE) {
        if (isDivisibleBy5(currNum)) {
            break;
        }
    }

    for (currNum; currNum < end; currNum += FIVE) {
        if (isDivisibleBy9(currNum)) {
            break;
        }
    }

    for (currNum; currNum < end; currNum += FOURTY_FIVE) {
        std::cout << currNum << "\n";
    }
    std::cout << std::endl;

    //performUnitTests();

    return 0;
}
