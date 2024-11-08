#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <_stdio.h>
#include <string>
#include <iostream>

# define PhonePrompt "PhoneBook-1.0$ "

class PhoneBook;

class Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkSecret;
		bool		statut;
	public:
		Contact(void);
		~Contact(void);
		bool	GetStatus() const;
		void	SetStatus(bool stat);
		void	SetFirstName(const std::string &str);
		void	SetLastName(const std::string &str);
		void	SetNickname(const std::string &str);
		void	SetPhoneNumber(const std::string &str);
		void	SetDarkSecret(const std::string &str);
		void	PrintPreData(const Contact &contact, int index) const;
};

class PhoneBook : public Contact
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	SetPhone();
		int		SetContact(const Contact &CurrentContact);
		void	SearchContacts();
	private:
		int OldestContact;
		Contact repertory[8];
};


#endif
