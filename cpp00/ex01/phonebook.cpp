/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:00 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/08 02:35:43 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <_stdio.h>
#include <cctype>

void	ErrorHandling(const std::string error, const std::string &context){
	std::cout << std::endl
		<< "PhoneBook: Error: " << error << context << std::endl << std::endl;
	throw (2);
}

PhoneBook::PhoneBook(void) : OldestContact(0){
	std::cout << "Constructor of Phonebook called" << std::endl << std::endl;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Destructor of PhoneBook called" << std::endl;
}

Contact::Contact(void) : statut(false){}

Contact::~Contact(void){}

bool	IsAlphaString(const std::string &tmp)
{
	for (int d = 0; tmp[d]; d++)
		if (!std::isalpha(tmp[d]))
			return (false);
	return (true);
}

bool	IsNumberFormat(const std::string &str)
{
	if (str.length() != 10 || (str[0] != '0' && str[0] != '+'))
		return (false);
	for (int d = 1; str[d]; d++)
		if (!std::isdigit(str[d]))
			return (false);
	return (true);

}

void	Contact::SetFirstName(const std::string &str){ FirstName = str; }

void	Contact::SetLastName(const std::string &str){ LastName = str; }

void	Contact::SetNickname(const std::string &str){ NickName = str; }

void	Contact::SetPhoneNumber(const std::string &str){ PhoneNumber = str; }

void	Contact::SetDarkSecret(const std::string &str) { DarkSecret = str; }


bool Contact::GetStatus() const{ return (this->statut); }

void Contact::SetStatus(bool stat){ this->statut = stat; }

int	PhoneBook::SetContact(const Contact &CurrentContact)
{
	int	index = 0;

	while (index < 8 && repertory[index].GetStatus() == true)
		index++;
	if (index == 8){
		index = OldestContact;
		OldestContact++;
	}
	repertory[index] = CurrentContact;
	return (index);
}

void	PhoneBook::SetPhone()
{
	Contact		CurrentContact;
	std::string tmp;

	std::cout << "\033c";
	std::cout << "(ADD MODE): Write the data requested" << std::endl;
	std::cout << "╔════════════════════════════════════" << std::endl << "║" << std::endl;
	std::cout << "╠═ Fisrt name: ";

	getline(std::cin, tmp);
	if (!IsAlphaString(tmp))
		ErrorHandling("Bad string format for Fist name: ", tmp);
	CurrentContact.SetFirstName(tmp);

	std::cout << "║" << std::endl << "╠═ Last name: ";
	
	getline(std::cin, tmp);
	if (!IsAlphaString(tmp))
		ErrorHandling("Bad string format for Last name: ", tmp);
	CurrentContact.SetLastName(tmp);
	
	std::cout << "║" << std::endl << "╠═ NickName: ";
	
	getline(std::cin, tmp);
	CurrentContact.SetNickname(tmp);
	
	std::cout << "║" << std::endl << "╠═ Phone number: ";
	
	getline(std::cin, tmp);
	if (!IsNumberFormat(tmp) && tmp != "")
		ErrorHandling("Bad string format for Phone Number: ", tmp);
	CurrentContact.SetPhoneNumber(tmp);
	
	std::cout << "║" << std::endl << "╠═ Dark secret: ";
	
	getline(std::cin, tmp);
	CurrentContact.SetDarkSecret(tmp);
	
	std::cout << "║" << std::endl << "╚════════════════════════════════════" << std::endl;
	
	CurrentContact.SetStatus(true);
	this->SetContact(CurrentContact);

	std::cout << std::endl << "The contact has been set correctly!" << std::endl << std::endl;
}

void	Contact::PrintPreData(const Contact &contact, int index) const
{
	std::cout << std::endl << index << " | " + contact.FirstName
		+ " | " + contact.LastName + " | " + contact.NickName << std::endl; 
}

void	PhoneBook::SearchContacts()
{
	std::cout << "\033c";
	std::cout << "(SEARCH MODE): Current contact available" << std::endl;
	std::cout << "╔════════════════════════════════════" << std::endl << "║" << std::endl;
	int	index = 0;

	while (index < 8 && repertory[index].GetStatus() == true)
		index++;
	if (index == 0)
	{
		std::cout << "║    No contact set !" << std::endl << "║" << std::endl;
		std::cout << "╚════════════════════════════════════" << std::endl << std::endl;
		throw (2);
	}
	for (int d = 0; d < index; d++){
		repertory[d].PrintPreData(repertory[d], d);
	  std::cout << std::endl;
	}
}

int	main(void)
{
	PhoneBook	phone;
	std::string	prompt;

	std::cout << "\033c";
	while (1)
	{
		std::cout << PhonePrompt;
		getline(std::cin, prompt);
		try
		{
			if (prompt == "ADD" || prompt == "add")
				phone.SetPhone();
			else if (prompt == "SEARCH" || prompt == "search")
				phone.SearchContacts();
			else if (prompt == "EXIT" || prompt == "exit"){
				std::cout << "exit" << std::endl;
				exit(0);
			}
			else {
				std::cout << "\033c";
				if (prompt != "")
					std::cout << "PhoneBook: " + prompt + ':' + " command not found" << std::endl;
			}
		}
		catch(int) {continue;}
	}
	return(0);
}
