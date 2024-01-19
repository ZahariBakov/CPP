#include "Book.h"

Book::Book(std::string title, std::string genre, int year, Author a) : author(a) {
	this->title = title;
	this->genre = genre;
	this->year = year;
}

std::string Book::getTitle() {
	return this->title;
}

void Book::print() {
	std::cout << this->title << " " << this->year << " " << this->genre << std::endl;
	author.print();
}
