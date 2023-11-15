#include <iostream>
#include <iomanip>

//int main() {
//
//    std::cin.sync_with_stdio(false);
//    std::cout.sync_with_stdio(false);
//
//    std::cout << "a\n";
//    printf("b\n");
//    std::cout << "c\n";
//
//    return 0;
//}

void basedOnSalaries(double& angelPay,
					 double& borislavaPay,
				     int angelSalary, 
					 int borislavaSalary, 
					 double totalPizzaPrice) {
	int totalSalaries = angelSalary + borislavaSalary;

	angelPay = angelSalary / (totalSalaries * 1.0) * totalPizzaPrice;
	borislavaPay += borislavaSalary / (totalSalaries * 1.0) *totalPizzaPrice;
}

void basedOnPizzaPieces(double& angelPay,
						double& borislavaPay,
						double totalPizzaPrice) {
	double onePizzaAveragePrice = totalPizzaPrice / 2;
	double oneThirdOfPizzaPrice = onePizzaAveragePrice / 3;

	angelPay += onePizzaAveragePrice + oneThirdOfPizzaPrice;
	borislavaPay += oneThirdOfPizzaPrice * 2;
}

void averagePay(double& angelPay,
				double& borislavaPay) {
	angelPay /= 2;
	borislavaPay /= 2;
}

void printSolution(double& angelPay,
				   double& borislavaPay,
				   double totalPizzaPrice) {
	std::cout << "Angel pay: " << std::setprecision(3) << angelPay << std::endl;
	std::cout << "Borislava pay: " << std::setprecision(3) << borislavaPay << std::endl;

	double weekPay = totalPizzaPrice * 5;
	std::cout << "Angel and Borislava pay for the week: " << weekPay << std::endl;
}

int main() {
	int firstPizzaPrice = 7;
	double secondPizzaPrice = firstPizzaPrice * 0.8;
	double totalPizzaPrice = firstPizzaPrice + secondPizzaPrice;
	

	int angelSalary = 1800;
	int borislavaSalary = 4000;

	double angelPay = 0;
	double borislavaPay = 0;

	basedOnSalaries(angelPay, borislavaPay, angelSalary, borislavaSalary, totalPizzaPrice);
	basedOnPizzaPieces(angelPay, borislavaPay, totalPizzaPrice);
	averagePay(angelPay, borislavaPay);
	printSolution(angelPay, borislavaPay, totalPizzaPrice);

	return 0;
}
