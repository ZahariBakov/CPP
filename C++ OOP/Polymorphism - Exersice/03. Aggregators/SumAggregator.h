#pragma once

#include "Aggregator.h"

class SumAggregator : public StreamAggregator {
public:
	SumAggregator(std::istream&);

	void aggregate(int) final;

private:

};
