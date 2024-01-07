#include "BookService.h"

Book BookService::inputData() {
	std::string author;
	std::string title;
	int yearOfIssue;
	double price;

	std::cout << "Enter Author: " << " ";
	std::getline(std::cin, author);

	std::cout << "Enter Book title: " << " ";
	std::getline(std::cin, title);

	std::cout << "Enter Year of issue: " << " ";
	std::cin >> yearOfIssue;

	std::cout << "Enter price: " << " ";
	std::cin >> price;

	std::cout << std::endl;

	Book myBook(author, title, yearOfIssue, price);

	return myBook;
}