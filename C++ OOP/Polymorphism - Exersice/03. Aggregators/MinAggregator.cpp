#include "MinAggregator.h"

#include <limits>
#include <cmath>

MinAggregator::MinAggregator(std::istream& stream) : StreamAggregator(stream) {
	aggregationResult = std::numeric_limits<int>::max();
}

void MinAggregator::aggregate(int next) {
	StreamAggregator::aggregate(next);

	/*if (aggregationResult > next) {
		aggregationResult = next;
	}*/

	aggregationResult = std::min(aggregationResult, next);
}
