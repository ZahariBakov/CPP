#include "SumAggregator.h"

SumAggregator::SumAggregator(std::istream& stream) : StreamAggregator(stream) {
	aggregationResult = 0;
}

void SumAggregator::aggregate(int next) {
	StreamAggregator::aggregate(next);

	aggregationResult += next;
}
