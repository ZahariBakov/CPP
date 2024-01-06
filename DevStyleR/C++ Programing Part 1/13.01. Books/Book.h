#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
public:
	Book(std::string, std::string, int, double);

	void setAuthor(std::string);
	void setBookName(std::string);
	void setYearOfIssue(int);
	void setPrice(double);

	double getPrice();
	std::string getAuthor();
	std::string getBookName();
	int getYear();

	void inputData();
	void displayMessage();

private:
	std::string author;
	std::string bookName;
	int yearOfIssue;
	double price;
};

#endif // !BOOK_H
