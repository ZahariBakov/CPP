#include "Address.h"
#include "Package.h"

int main() {
    Address sender("Ivan Petrov", "088910265", "Sofia", "Tsarigradsko shose 159");
    Address recepient("Petur Stoianov", "0887563217", "Pleven", "Rila 4");

    Package package(2.50, 3.07, sender, recepient);
    package.print();

    return 0;
}
