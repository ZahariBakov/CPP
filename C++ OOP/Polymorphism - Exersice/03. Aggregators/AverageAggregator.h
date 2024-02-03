#pragma once

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator {
public:
	AverageAggregator(std::istream&);

	void aggregate(int) final;

private:
	int _currSum = 0;
};
