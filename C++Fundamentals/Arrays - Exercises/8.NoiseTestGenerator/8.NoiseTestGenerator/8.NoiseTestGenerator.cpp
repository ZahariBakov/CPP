#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>

int getRandomNumber(int lowRange, int highRange) {
	return lowRange + (rand() % (highRange - lowRange + 1));
}

char generateRandomDigitCharacter() {
	const int randomNumber = getRandomNumber(0, 9);

	return char(randomNumber + '0');
}

char generateRandomSymbol() {
	static const std::array<char, 5> symbols = { '.', '!', '?', '@', ':' };
	const int index = getRandomNumber(0, symbols.size() - 1);
	const char chosenSymbol = symbols[index];

	return chosenSymbol;
}

int main() {
	srand(time(nullptr));
	std::array<char, 1000> arr{};
	int currCharIdx = 0;

	const int digitToGenerate = getRandomNumber(2, 9);

	for (int i = 0; i < digitToGenerate; i++) {
		arr[currCharIdx] = generateRandomDigitCharacter();
		currCharIdx++;
	}

	const int randomSymbolsToGenerate = getRandomNumber(0, 5);

	for (int j = 0; j < randomSymbolsToGenerate; ++j) {
		arr[currCharIdx] = generateRandomSymbol();
		currCharIdx++;
	}

	int usedArraySize = currCharIdx;

	arr[usedArraySize] = '.';
	usedArraySize++;

	for (int i = 0; i < usedArraySize; i++) {
		std::cout << arr[i];
	}
	std::cout << std::endl;

	return 0;
}
