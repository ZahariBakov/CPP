#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include "Company.h"
#include "ProfitCalculator.h"

std::string getProfitReport(Company* fromInclusive, Company* toInclusive, const std::map<int, ProfitCalculator>& profitCalculatorsByCompany) {
	std::ostringstream report;

	for (Company* c = fromInclusive; c <= toInclusive; ++c) {
		int id = c->getId();
		ProfitCalculator calc = profitCalculatorsByCompany.find(id)->second;
		report << c->getName() << " = " << calc.calculateProfit(*c);

		if (c != toInclusive) {
			report << std::endl;
		}
	}

	return report.str();
}

#endif // !PROFIT_REPORT_H