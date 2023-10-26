// Lector decision:

#include <iostream>
#include <string>
#include <array>

const int arrSize = 255;

void readInput(std::string& digitRepresentation,
	           std::string& firstNumber,
	           std::string& secondNumber) {
	std::cin >> digitRepresentation >> firstNumber >> secondNumber;
}

std::array<int, arrSize> getIntDigitsRepresentation(
	const std::string& digitRepresentation) {
	std::array<int, arrSize> arr{ };

	const size_t size = digitRepresentation.size();

	for (size_t i = 0; i < size; ++i) {
		const int index = digitRepresentation[i];
		arr[index] = i;
	}

	return arr;
}

int getIntFromString(const std::string& numberStr,
					 const std::array<int, arrSize>& intDogits) {
	int number = 0;

	for (const char digit : numberStr) {
		number *= 10;
		number += intDogits[digit];
	}

	return number;
}

int getDigitFromChar(char c) {
	return c - '0';
}

std::string getNumberRepresentation(const std::string& digitRepresentation, 
									int number) {
	std::string numberRepresentationString;
	const std::string numberStr = std::to_string(number);

	for (const char letter : numberStr) {
		const int digitIndex = getDigitFromChar(letter);
		const char newLetter = digitRepresentation[digitIndex];
		numberRepresentationString.push_back(newLetter);
	}

	return numberRepresentationString;
}

int main() {
	std::string digitRepresentation;
	std::string firstNumberStr;
	std::string secondNumberStr;

	readInput(digitRepresentation, firstNumberStr, secondNumberStr);

	const std::array<int, arrSize> intDigits = getIntDigitsRepresentation(digitRepresentation);

	const int firstNumber = getIntFromString(firstNumberStr, intDigits);
	const int secondNumber = getIntFromString(secondNumberStr, intDigits);
	const int sum = firstNumber + secondNumber;

	const std::string numberRepresentationString = getNumberRepresentation(digitRepresentation, sum);

	std::cout << numberRepresentationString << std::endl;

	return 0;
}


// My decision:

//#include <iostream>
//#include <string>
//#include <sstream>
//#include <vector>
//#include <algorithm>
//
//void readInput(std::string& digitRepresentation, 
//               std::string& firstNumber,
//               std::string& secondNumber) {
//    std::cin >> digitRepresentation >> firstNumber >> secondNumber;
//}
//
//int currentSum(const std::string& digitRepresentation, const std::string& number) {
//    int currentSum = 0;
//    size_t size = number.size();
//
//    for (size_t i = 0; i < size; ++i) {
//        std::string::const_iterator it = std::find(digitRepresentation.begin(), digitRepresentation.end(), number[i]);
//        currentSum *= 10;
//        currentSum += (it - digitRepresentation.begin());
//    }
//
//    return currentSum;
//}
//
//std::string convertSumToSymbol(const std::string& digitRepresentation, int sum) {
//    std::string result;
//    std::vector<int> numbers;
//
//    while (sum > 0) {
//        int currentNum = sum % 10;
//        sum /= 10;
//        numbers.push_back(currentNum);
//    }
//
//    size_t size = numbers.size();
//
//    for (int i = (size - 1); i >= 0; --i) {
//        int currentIdx = numbers[i];
//        result += digitRepresentation[currentIdx];
//    }
//
//    return result;
//
//}
//
//int main() {
//    std::string digitRepresentation;
//    std::string firstNumber;
//    std::string secondNumber;
//
//    readInput(digitRepresentation, firstNumber, secondNumber);
//    int firstSum = currentSum(digitRepresentation, firstNumber);
//    int secondSum = currentSum(digitRepresentation, secondNumber);
//    int totalSum = firstSum + secondSum;
//
//    std::string outputSymbol = convertSumToSymbol(digitRepresentation, totalSum);
//
//    std::cout << outputSymbol << std::endl;
//
//    return 0;
//}