#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	std::cout << "contact has been created" << std:: endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "contact has been destroyed" << std:: endl;
	return ;
}
