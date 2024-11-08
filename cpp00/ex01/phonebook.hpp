#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define PhonePrompt "PhoneBook-1.0.1$ "
# define CHARGEPROMPT "⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏"

#include "contact.hpp"

#include <iostream>
#include <ostream>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	setPhone();
		int		setContact(const Contact &CurrentContact);
		void	searchContacts();
		void	indexPrint();
	private:
		int _oldestContact;
		Contact _repertory[8];
};

void	LoopPrompt();
bool	IsAlphaString(const std::string &tmp);
bool	IsNumberFormat(const std::string &str, size_t laine);

#endif
