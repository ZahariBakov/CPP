#include "Drinks.h"
#include "Alcoholic.h"
#include "NonAlcoholic.h"

int main() {
    Alcoholic a1("Jack Daniels", 25.80, 1, "whiskey", 38.5, 3);
    a1.print();

    NonAlcoholic na1("Lavazza", 1.5, 1, "coffee", 0.1, 0.5);
    na1.print();

    return 0;
}
