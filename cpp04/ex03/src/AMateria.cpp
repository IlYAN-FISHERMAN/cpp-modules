/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:13:53 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/12 19:42:22 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/AMateria.hpp"

AMateria::AMateria(){
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::~AMateria(){
	std::cout << "AMateria default deconstructor" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type){}

AMateria::AMateria(const AMateria &other) : _type(other._type){}

AMateria& AMateria::operator=(const AMateria &other){
	if (this != &other)
		_type = other._type;
	return (*this);
}

std::string const & AMateria::getType() const{return (_type);}

void AMateria::use(ICharacter& target){
	std::cout << target.getName() << " Use something" << std::endl;
}
