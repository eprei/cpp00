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
	std::string str_exit ("EXIT");
	std::string str_search ("SEARCH");

	while (!(this->_prompt.compare(str_exit) == 0))
	{
		std::cout << "Phonebook : ";
		std::getline (std::cin, this->_prompt);
		if(str_exit.compare(this->_prompt) == 0)
			this->_exit_status = true;
		else if(str_add.compare(this->_prompt) == 0)
			ft_add_contact();
		else if(str_search.compare(this->_prompt) == 0)
			ft_search();
	}
	return ;
}

void	PhoneBook::ft_add_contact(void)
{
	std::string buff;
	int i = Contact::get_nb_inst() % 8;

	std::cout << "First name: ";
	std::cin >> buff;
	this->_contact[i].set_first_name(buff);

	std::cout << "Last name: ";
	std::cin >> buff;
	this->_contact[i].set_last_name(buff);

	std::cout << "Nickname: ";
	std::cin >> buff;
	this->_contact[i].set_nickname(buff);

	std::cout << "Phone number: ";
	std::cin >> buff;
	this->_contact[i].set_phone_number(buff);

	std::cout << "Darkest secret: ";
	std::cin >> buff;
	this->_contact[i].set_darkest_secret(buff);

	this->_contact[i].set_index(i + 1);
	Contact::add_nb_inst();

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return ;
}

void	PhoneBook::ft_search(void)
{
	int i = -1;
	std::string str_tmp ("\n");

	if (Contact::get_nb_inst() == 0)
	{
		std::cout << "The contact list is empty" << std::endl;
		return ;
	}
	print_all_contacts();
	while (i > Contact::get_nb_inst() || i > 8 || i < 1)
	{
		std::cout << "Please enter a valid index number: ";
		std::cin >> i;
		if (i > Contact::get_nb_inst() || i > 8 || i < 1)
		{
			std::cout << "Invalid index number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	this->_contact[i - 1].print_full_contact();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return ;
}

void	PhoneBook::print_all_contacts(void) const
{
	for (int i = 0; i < 8 && i < Contact::get_nb_inst(); i++)
		this->_contact[i].print_contact();
	return ;
}
