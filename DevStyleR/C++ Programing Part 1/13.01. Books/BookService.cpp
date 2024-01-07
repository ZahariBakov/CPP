#include "BookService.h"

Book BookService::inputData() {
	std::string author;
	std::string bookName;
	int yearOfIssue;
	double price;

	std::cout << "Enter Author: " << " ";
	std::getline(std::cin, author);

	std::cout << "Enter Book name: " << " ";
	std::getline(std::cin, bookName);

	std::cout << "Enter Year of issue: " << " ";
	std::cin >> yearOfIssue;

	std::cout << "Enter price: " << " ";
	std::cin >> price;

	std::cout << std::endl;

	Book myBook(author, bookName, yearOfIssue, price);

	return myBook;
}