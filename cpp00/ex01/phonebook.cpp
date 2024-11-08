/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:00 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/08 15:42:46 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cstdlib>
#include <sstream>
#include <string>

void	ErrorHandling(const std::string error, const std::string &context, bool print = false){
	(print == true) ?
		std::cout << "║               PhoneBook: Error: " << error << context << std::endl
		: std::cout << "                PhoneBook: Error: " << error << context << std::endl;
}


PhoneBook::PhoneBook(void) : _oldestContact(0){
	std::cout << "Constructor of Phonebook called" << std::endl << std::endl;
}

PhoneBook::~PhoneBook(void){
	std::cout << std::endl << "Destructor of PhoneBook called" << std::endl;
}

void	PhoneBook::setPhone()
{
	Contact		CurrentContact;
	std::string tmp;

	std::cout << "\033c";
	std::cout << "(ADD MODE): Write the data requested" << std::endl;
	std::cout << "╔════════════════════════════════════" << std::endl << "║" << std::endl;

	while (1)
	{
		std::cout << "╠═ First name: ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
		if (!IsAlphaString(tmp) || tmp == ""){
			std::cout << "\033[F\033[K\033[F\033[K";
			ErrorHandling("Bad string format for Fist name: ", tmp, true);
			continue;
		}
		CurrentContact.setFirstName(tmp);
		break ;
	}
	std::cout << "║" << std::endl;
	while(1)
	{
		std::cout << "╠═ Last name: ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
		if (!IsAlphaString(tmp) || tmp == ""){
			std::cout << "\033[F\033[K\033[F\033[K";
			ErrorHandling("Bad string format for Last name: ", tmp, true);
			continue;
		}
		CurrentContact.setLastName(tmp);
		break ;
	}
	std::cout << "║" << std::endl;
	while(1)
	{
		std::cout << "╠═ NickName: ";	
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
		if (tmp == ""){
			std::cout << "\033[F\033[K\033[F\033[K";
			ErrorHandling("Bad string format for Nickname: ", tmp, true);
			continue;
		}
		CurrentContact.setNickname(tmp);
		break ;
	}
	std::cout << "║" << std::endl;
	while (1)
	{
		std::cout << "╠═ Phone number: ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
		if (!IsNumberFormat(tmp, 10) || tmp == ""){
			std::cout << "\033[F\033[K\033[F\033[K";
			ErrorHandling("Bad string format for Phone Number: ", tmp, true);
			continue;
		}
		CurrentContact.setPhoneNumber(tmp);
		break ;
	}
	std::cout << "║" << std::endl;
	while (1)
	{
		std::cout << "╠═ Dark secret: ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
		if (tmp == ""){
			std::cout << "\033[F\033[K\033[F\033[K";
			ErrorHandling("Bad string format for Nickname: ", tmp, true);
			continue;
		}
		CurrentContact.setDarkSecret(tmp);
		break;
	}
	std::cout << "║" << std::endl << "╚════════════════════════════════════" << std::endl;
	CurrentContact.setStatus(true);
	this->setContact(CurrentContact);
	LoopPrompt();
	std::cout << std::endl << "The contact has been set correctly!" << std::endl << std::endl;
}

void	Contact::printPreData(const Contact &contact, int index) const
{
	int		laine = 0;
	int		laineescape = 0;

	std::cout << "║   " << index << "   ║   ";

	laine = contact._firstName.length();
	if (laine > 10)
	{
		for (int d = 0; contact._firstName[d] && d < 10; d++)
			std::cout << contact._firstName[d];
		std::cout << ".║  ";
	}
	else
	{
		laineescape = 10 - laine;
		while (laineescape > 0){
			std::cout << " ";
			laineescape--;
		}
		for (int d = 0; d < laine; d++)
			std::cout << contact._firstName[d];
		std::cout << " ║  ";
	}
	laineescape = 0;
	
	laine = contact._lastName.length();
	if (laine > 10)
	{
		for (int d = 0; contact._lastName[d] && d < 10; d++)
			std::cout << contact._lastName[d];
		std::cout << ".║  ";
	}
	else
	{
		laineescape = 10 - laine;
		while (laineescape > 0){
			std::cout << " ";
			laineescape--;
		}
		for (int d = 0; d < laine; d++)
			std::cout << contact._lastName[d];
		std::cout << " ║  ";
	}
	laineescape = 0;
	
	laine = contact._nickName.length();
	if (laine > 10)
	{
		for (int d = 0; contact._nickName[d] && d < 10; d++)
			std::cout << contact._nickName[d];
		std::cout << ".║  ";
	}
	else
	{
		laineescape = 10 - laine;
		while (laineescape > 0){
			std::cout << " ";
			laineescape--;
		}
		for (int d = 0; d < laine; d++)
			std::cout << contact._nickName[d];
		std::cout << " ║  ";
	}

}

void	Contact::printIndexRep(void) const
{
	std::cout << "║  First name:    " + this->_firstName << std::endl;
	std::cout << "║  Last name:     " + this->_lastName << std::endl;
	std::cout << "║  Nickname:      " + this->_nickName << std::endl;
	std::cout << "║  Phone number:  " + this->_phoneNumber << std::endl;
	std::cout << "║  Dark secret:   " + this->_darkSecret << std::endl;
}

void	PhoneBook::indexPrint()
{
	std::string tmp;
	int nb = 0;

	while (1)
	{
		std::cout << "which index do you want to print ?: ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			return ;
		if (!IsNumberFormat(tmp, 1)){
			std::cout << "\033[F\033[K\033[F\033[K";
			ErrorHandling("Bad string format for index: ", tmp);
			continue;
		}
		else{
			std::stringstream	index;
			index << tmp;
			index >> nb;
			if(nb < 0 || nb > 8 || _repertory[nb].getStatus() == false){
				std::cout << "\033[F\033[K\033[F\033[K";
				ErrorHandling("No contact set at index: ", tmp);
				nb = 0;
				tmp = "";
				continue;
			}
			std::cout << "╔═══════════════════════════════════════════" << std::endl;
			_repertory[nb].printIndexRep();
			std::cout << "╚═══════════════════════════════════════════" << std::endl << std::endl;
		}
		break ;
	}
}

void	PhoneBook::searchContacts()
{
	int	index = 0;

	while (index < 8 && _repertory[index].getStatus() == true)
		index++;
	if (index == 0)
	{
		std::cout << "\033c";
		std::cout << "(SEARCH MODE): Current contact available" << std::endl;
		std::cout << "╔═══════════════════════════════════════════" << std::endl;
		std::cout << "║" << std::endl << "║    No contact set !" << std::endl << "║" << std::endl;
		std::cout << "╚═══════════════════════════════════════════" << std::endl << std::endl;
		throw (2);
	}
	std::cout << "\033c";
	std::cout << "(SEARCH MODE): Current contact available" << std::endl;
	std::cout << "╔═══════╦══════════════╦═════════════╦═════════════╗" << std::endl;
	std::cout << "║ index ║  First Name  ║  Last Name  ║  Nick Name  ║" << std::endl;
	std::cout << "╠═══════╬══════════════╬═════════════╬═════════════╣" << std::endl;
	for (int d = 0; d < index; d++){
		_repertory[d].printPreData(_repertory[d], d);
	  std::cout << std::endl;
	}
	std::cout << "╚═══════╩══════════════╩═════════════╩═════════════╝" << std::endl << std::endl;
	this->indexPrint();
}

int	main(void)
{
	PhoneBook	phone;
	std::string	prompt;

	std::cout << "\033c";
	while (1)
	{
		std::cout << PhonePrompt;
		std::getline(std::cin, prompt);
		if (std::cin.eof())
			return (1);
		try
		{
			if (prompt == "ADD" || prompt == "add")
				phone.setPhone();
			else if (prompt == "SEARCH" || prompt == "search")
				phone.searchContacts();
			else if (prompt == "EXIT" || prompt == "exit"){
				std::cout << "exit" << std::endl;
				return (0);
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
