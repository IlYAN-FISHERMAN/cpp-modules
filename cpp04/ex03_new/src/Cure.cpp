/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:44 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/13 11:51:26 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Cure.hpp"

Cure::Cure() : AMateria("cure"){
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure(){
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other){
	std::cout << "Cure copy constructor" << std::endl;
}

Cure::Cure(const std::string name) : AMateria(name){
	std::cout << "Cure copy name constructor" << std::endl;
}

Cure& Cure::operator=(const Cure &other){
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria* Cure::clone() const{return (new Cure());}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
