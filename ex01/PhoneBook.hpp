#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook{

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	start_phone(void);
	void	get_promp_from_cin(void);
	bool	evaluate_prompt(void);
	bool	get_exit_status(void) const;
	void	set_exit_status(int i);
	void	ft_add_contact(void);
	void	ft_search(void);
	void	print_all_contacts(void) const;

private:

	std::string _prompt;
	Contact _contact[8];
	bool	_exit_status;
};

#endif
