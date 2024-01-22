#include "Shop.h"

Shop::Shop(std::vector<User*> users) : _users(users) {}

void Shop::soldDrinks() {
	int soldAlcoholic = 0;
	int soldNonAlcoholic = 0;

	for (size_t i = 0; i < _users.size(); ++i) {
		auto userOrders = _users[i]->getOrders();

		for (auto order : userOrders) {
			auto userDrinks = order->getDrinks();

			for (auto drink : userDrinks) {
				Alcoholic* alcoholic = dynamic_cast<Alcoholic*>(drink);

				if (alcoholic) {
					soldAlcoholic++;
				}
				else {
					soldNonAlcoholic++;
				}
			}
		}
	}

	std::cout << "Alcoholic: " << soldAlcoholic << " non alcoholic: " << soldNonAlcoholic << std::endl;
}
