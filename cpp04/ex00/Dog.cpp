/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:09:26 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/03 02:19:07 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor called with type " << _type << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called with type " << _type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other._type){
	std::cout << "Dog copy constructor called with type " << _type << std::endl;
}

Dog& Dog::operator=(const Dog &other){
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::Dog(std::string type) : Animal(type){
	std::cout << "Dog constructor called with type " << _type << std::endl;
}

void Dog::makeSound(void) const{
	std::cout << "Dog say ouaaafff!" << std::endl;
}
