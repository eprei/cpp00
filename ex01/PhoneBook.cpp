#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook has been created" << std:: endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook has been destroyed" << std:: endl;
	return ;
}
