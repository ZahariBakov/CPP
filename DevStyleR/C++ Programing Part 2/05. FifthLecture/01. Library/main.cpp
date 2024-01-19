#include "Author.h"
#include "Book.h"

#include <vector>

int main() {
    Author a1("Harper", "Lee", "American");
    //a1.print();

    Author a2("Stephen", "King", "American");
    //a2.print();

    Author a3("Joanne", "Rowling", "British");
    Author a4("Walter", "Isaacson", "American");
    Author a5("Casey", "McQuiston", "American");

    Book b1("To Kill a Mockingbird", "", 1960, a1);
    //b1.print();

    Book b2("Fairy Tale", "", 2022, a2);
    //b2.print();

    Book b3("Harry Potter and the Philosopher's Stone", "", 1997, a3);
    Book b4("Steve Jobs", "", 2011, a4);
    Book b5("Red, White & Royal Blue", "", 2019, a5);

    std::vector<Book> libarary;
    libarary.push_back(b1);
    libarary.push_back(b2);
    libarary.push_back(b3);
    libarary.push_back(b4);
    libarary.push_back(b5);

    std::cout << "All available books inour library is: " << std::endl;
    for (size_t i = 0; i < libarary.size(); ++i) {
        libarary[i].print();
    }

    return 0;
}
