#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
class PhoneBook{

public:

	PhoneBook(void);
	~PhoneBook(void);

private:

	Contact _contact[8];
};

#endif
