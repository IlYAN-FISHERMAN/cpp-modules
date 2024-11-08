/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setfunction.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:11:21 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/08 16:03:13 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

void	Contact::setFirstName(const std::string &str){ _firstName = str; }

void	Contact::setLastName(const std::string &str){ _lastName = str; }

void	Contact::setNickname(const std::string &str){ _nickName = str; }

void	Contact::setPhoneNumber(const std::string &str){ _phoneNumber = str; }

void	Contact::setDarkSecret(const std::string &str) { _darkSecret = str; }

void Contact::setStatus(bool stat){ this->_statut = stat; }

int	PhoneBook::setContact(const Contact &CurrentContact)
{
	int	index = 0;

	while (index < 8 && _repertory[index].getStatus() == true)
		index++;
	if (index == 8){
		index = _oldestContact;
		_oldestContact++;
		if (_oldestContact > 8)
			_oldestContact = 0;
	}
	_repertory[index] = CurrentContact;
	return (index);
}
