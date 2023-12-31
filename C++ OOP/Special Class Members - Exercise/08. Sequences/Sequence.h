#ifndef SEQUENCES_H
#define SEQUENCES_H

#include <vector>

template<typename T, typename Generator>
class Sequence {
public:
	class Iterator {
	public:
		static Iterator getBegin(const std::vector<T>& sequenceElements) {
			return Iterator(sequenceElements, 0);
		}

		static Iterator getEnd(const std::vector<T>& sequenceElements) {
			return Iterator(sequenceElements, -1);
		}

		const T& operator*() const {
			return this->sequenceElements.at(this->indexInSequence);
		}

		Iterator& operator++() {
			this->indexInSequence++;
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return !(*this == other);
		}

		bool operator==(const Iterator& other) const {
			bool sequencesMatch = this->sequenceElements == other.sequenceElements;
			bool bothPositionsAreEnd = isEndIndex(this->indexInSequence, this->sequenceElements)
				&& isEndIndex(other.indexInSequence, other.sequenceElements);
			bool positionMatch = this->indexInSequence == other.indexInSequence;

			return sequencesMatch && (bothPositionsAreEnd || positionMatch);
		}

	private:
		const std::vector<T>& sequenceElements;
		int indexInSequence;

		Iterator(const std::vector<T>& sequenceElements, int indexInSequence)
			: sequenceElements(sequenceElements), indexInSequence(indexInSequence) {}

		static int isEndIndex(int index, const std::vector<T>& sequenceElements) {
			return index == -1 || index == sequenceElements.size();
		}
	};

	void generateNext(int n) {
		for (int i = 0; i < n; ++i) {
			this->generated.push_back(this->generator());
		}
	}

	Iterator begin() const {
		return Iterator::getBegin(this->generated);
	}

	Iterator end() const {
		return Iterator::getEnd(this->generated);
	}
private:
	Generator generator;
	std::vector<T> generated;
};

#endif // !SEQUENCES_H
