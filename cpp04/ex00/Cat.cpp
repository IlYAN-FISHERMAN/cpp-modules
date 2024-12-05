/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:43:10 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/03 02:18:52 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat default constructor called with type " << _type << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called with type " << _type << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other._type){
	std::cout << "Cat copy constructor called with type " << _type << std::endl;
}

Cat& Cat::operator=(const Cat &other){
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::Cat(std::string type) : Animal(type){
	std::cout << "Cat constructor called with type " << _type << std::endl;
}

void Cat::makeSound(void) const{
	std::cout << "Cat say miaouuu!" << std::endl;
}
