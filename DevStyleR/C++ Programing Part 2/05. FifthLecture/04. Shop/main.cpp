#include "Drinks.h"
#include "Alcoholic.h"
#include "NonAlcoholic.h"
#include "Order.h"

int main() {
    Drinks* a1Ptr = new Alcoholic("Jack Daniels", 25.80, 1, "whiskey", 38.5, 3);
    Drinks* a2Ptr = new Alcoholic("Finlandia", 28.90, 2, "vodka", 38.5, 3);

    Drinks* na1Ptr = new NonAlcoholic("Lavazza", 1.5, 1, "coffee", 0.1, 0.5);
    Drinks* na2Ptr = new NonAlcoholic("NesTea", 3.5, 3, "tea", 1.5, 0.5);

    std::vector<Drinks*> drinks;

    drinks.push_back(a1Ptr);
    drinks.push_back(a2Ptr);
    drinks.push_back(na1Ptr);
    drinks.push_back(na2Ptr);

    Order o1(drinks, "22.01.2024");
    o1.printOrder();

    return 0;
}
