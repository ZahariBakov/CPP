#include "Word.h"

#include <iostream>

std::unordered_map<std::string, int> Word::_wordCount{};

// Set solution
//std::multiset<std::string> Word::_wordSet{};

Word::Word(const std::string& word) : _word(word) {
	_wordCount[_word]++;

	// Set solution
	//_wordSet.insert(_word);
}

bool Word::operator<(const Word& other) const {
	return _word < other._word;
}

std::string Word::getWord() const {
	return _word;
}

int Word::getCount() const {
	const auto it = _wordCount.find(_word);
	if (it != _wordCount.end()) {
		const int count = it->second;
		it->second = 0;
		return count;
	}

	std::cerr << "Didi not find: " << _word << std::endl;
	return 0;

	// return for map solution:
	//const int count = _wordCount[_word];
	//_wordCount[_word] = 0;
	//return count;
	
	// return for set solution:
	//return _wordSet.erase(_word);
}