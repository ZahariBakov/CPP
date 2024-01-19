#pragma once

#include "Author.h"

class Book {
public:
	Book(std::string, std::string, int, Author);

	std::string getTitle();

	void print();

private:
	std::string title;
	std::string genre;
	int year;
	Author author;
};
