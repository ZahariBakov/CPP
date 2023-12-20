#ifndef WORD_H
#define WORD_H

#include <string>
#include <unordered_map>
#include <set>

class Word {
public:
	Word(const std::string& word);

	bool operator<(const Word& other) const;

	std::string getWord() const;

	int getCount() const;
	
private:
	std::string _word;
	static std::unordered_map<std::string, int> _wordCount;

	// Set solution
	//static std::multiset<std::string> _wordSet;
};

#endif // !WORD_H
