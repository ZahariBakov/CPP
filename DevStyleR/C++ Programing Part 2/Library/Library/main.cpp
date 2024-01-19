#include "Author.h"
#include "Book.h"
#include "Library.h"

int main() {
    enum Genre { CLASSIC, CRIME, FANTASY };

    Author author("john", "Doe", "GB");
    //author.print()

    Book b1("BookTitle", "classic", 2020, author);
    Book b2("Book2Title", "crime", 2021, author);

    Library library;
    library.print();

    library.addBook(b1);
    library.addBook(b2);

    library.print();

    library.findBook("2");

    return 0;
}
