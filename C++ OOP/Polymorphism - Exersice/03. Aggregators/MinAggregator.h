#pragma once

#include "Aggregator.h"

class MinAggregator : public StreamAggregator {
public:
	MinAggregator(std::istream&);

	void aggregate(int) final;

private:

};
