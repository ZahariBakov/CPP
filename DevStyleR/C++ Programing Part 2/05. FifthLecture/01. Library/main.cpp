#include "Author.h"
#include "Book.h"

int main() {
    Author a1("Harper", "Lee", "American");
    //a1.print();

    Author a2("Stephen", "King", "American");
    //a2.print();

    Book b1("To Kill a Mockingbird", "", 1960, a1);
    b1.print();

    Book b2("Fairy Tale", "", 2022, a2);
    b2.print();

    return 0;
}
