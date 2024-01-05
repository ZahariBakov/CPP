#include <iostream>
#include <vector>

#include "Book.h"
#include "BookService.h"

int main() {
    std::vector<Book> books;
    double mostExpensiveBook = 0.00;
    double mostCheapestBook = 1500.00;
    int indexExpensive = 0;
    int indexCheapest = 0;

    BookService bs;

    for (int i = 0; i < 4; ++i) {
        Book myBook = bs.inputData();
        books.push_back(myBook);
    }

    for (int j = 0; j < books.size(); ++j) {
        if (books.at(j).getPrice() > mostExpensiveBook) {
            mostExpensiveBook = books.at(j).getPrice();
            indexExpensive = j;
        }

        if (books.at(j).getPrice() < mostCheapestBook) {
            mostCheapestBook = books.at(j).getPrice();
            indexCheapest = j;
        }
    }

    std::cout << "Most expensive book is: ";
    books.at(indexExpensive).displayMessage();
    std::cout << "\n";

    std::cout << "Most cheapest book is: ";
    books[indexCheapest].displayMessage();
    std::cout << std::endl;

    return 0;
}
