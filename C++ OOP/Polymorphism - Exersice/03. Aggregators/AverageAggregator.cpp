#include "AverageAggregator.h"

AverageAggregator::AverageAggregator(std::istream& stream) : StreamAggregator(stream) {
	aggregationResult = 0;
}

void AverageAggregator::aggregate(int next) {
	StreamAggregator::aggregate(next);

	_currSum += next;
	aggregationResult = _currSum / StreamAggregator::getNumAggregated();
}
