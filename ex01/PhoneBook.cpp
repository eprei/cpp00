#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	// std::cout << "PhoneBook has been created" << std:: endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook has been destroyed" << std:: endl;
	return ;
}

void	PhoneBook::get_promp_from_cin(void)
{
	std::cout << "Phonebook : ";
	std::getline (std::cin, this->_prompt);
	return ;
}

bool	PhoneBook::evaluate_prompt(void)
{
	std::string str_add ("ADD");
	std::string str_search ("SEARCH");
	std::string str_exit ("EXIT");

	if (str_exit.compare(this->_prompt) == 0)
		this->_exit_status = true;
	else if (str_add.compare(this->_prompt) == 0 || str_search.compare(this->_prompt) == 0)
		return (true);
	return (false);
}

bool	PhoneBook::get_exit_status(void) const
{
	return this->_exit_status;
}

void	PhoneBook::set_exit_status(int i)
{
	if (i == 1)
		this->_exit_status = true;
	else
		this->_exit_status = false;
	return ;
}

void	PhoneBook::start_phone(void)
{
	std::string str_add ("ADD");
	std::string str_search ("SEARCH");

	PhoneBook::get_promp_from_cin();
	if (PhoneBook::evaluate_prompt() == true)
	{
		if(str_add.compare(this->_prompt) == 0)
			ft_add_contact();
		else if(str_search.compare(this->_prompt) == 0)
			ft_search();
	}
	return ;
}

void	PhoneBook::ft_add_contact(void)
{
	Contact new_contact;
	std::string buff;

	std::cout << "First name: ";
	std::cin >> buff;
	new_contact.set_first_name(buff);
	buff.clear();

	std::cout << "Last name: ";
	std::cin >> buff;
	new_contact.set_last_name(buff);
	buff.clear();

	std::cout << "Nickname: ";
	std::cin >> buff;
	new_contact.set_nickname(buff);
	buff.clear();

	std::cout << "Phone number: ";
	std::cin >> buff;
	new_contact.set_phone_number(buff);
	buff.clear();

	std::cout << "Darkest secret: ";
	std::cin >> buff;
	new_contact.set_darkest_secret(buff);

	new_contact.print_contact();
	this->_contact[Contact::get_nb_inst() % 8 - 1] = new_contact;

	std::cout << "numero de contactos = " << Contact::get_nb_inst() % 8 << std::endl;
	return ;
}

void	PhoneBook::ft_search(void)
{
	print_all_contacts();
	return ;
}

void	PhoneBook::print_all_contacts(void) const
{
	for (int i = 0; i < 8; i++)
		this->_contact[i].print_contact();
	return ;
}
