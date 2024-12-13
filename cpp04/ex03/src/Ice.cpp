/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:17:16 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/12 17:53:34 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice(){
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other){
	std::cout << "Ice copy constructor" << std::endl;
}

Ice::Ice(const std::string name) : AMateria(name){
	std::cout << "Ice copy name constructor" << std::endl;
}

Ice& Ice::operator=(const Ice &other){
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria* AMateria::clone() const{return (new Ice());}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
}
