/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:43:10 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/05 16:30:02 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("chapoter"){
	std::cout << "Cat " << _type << " default constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat " << _type << " destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other._type){
	std::cout << "Cat " << _type << " copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other){
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::Cat(std::string type) : Animal(type){
	std::cout << "Cat " << _type << " constructor called" << std::endl;
}

void Cat::makeSound(void) const{
	std::cout << "Cat " << _type << " say miaouuu!" << std::endl;
}
