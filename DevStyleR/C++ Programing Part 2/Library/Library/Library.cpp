#include "Library.h"

void Library::addBook(Book b) {
	this->books.push_back(b);
}

void Library::print() {
	for (Book book : books) {
		book.print();
	}
}

void Library::findBook(std::string text) {
	for (Book book : books) {
		//if (book.getTitle().find(text) != -1) {
		if (book.getTitle().find(text) != std::string::npos) {
			std::cout << "We found the book " << std::endl;
			book.print();
			break;
		}
	}
}
