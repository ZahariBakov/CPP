#include <iostream>
#include <sstream>
#include <queue>

class SentenceShifter {
public:
    void readInput() {
        std::string line;
        getline(std::cin, line);

        std::istringstream istr(line);

        std::string word;
        while (istr >> word) {
            _words.push_back(word);
        }

        std::cin >> _shiftsCount;
    }

    void shiftWords() {
        if (_words.empty()) {
            return;
        }

        for (size_t i = 0; i < _shiftsCount; ++i) {
            const auto lastWord = _words.back();
            _words.pop_back();
            _words.push_front(lastWord);
        }
    }

    std::deque<std::string> getShiftedSentence() {
        return _words;
    }

private:
    std::deque<std::string> _words;
    size_t _shiftsCount = 0;
};

int main() {
    SentenceShifter shifter;
    shifter.readInput();
    shifter.shiftWords();
    const auto shiftedWords = shifter.getShiftedSentence();

    for (const auto& word : shiftedWords) {
        std::cout << word << '\n';
    }

    return 0;
}

