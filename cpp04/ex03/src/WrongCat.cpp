/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:49:13 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/05 18:59:57 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("paslechapoter"){
	std::cout << "WrongCat " << _type << " default constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat " << _type << " destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other._type){
	std::cout << "WrongCat " << _type << " copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other){
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type){
	std::cout << "WrongCat " << _type << "constructor called" << std::endl;
}

void WrongCat::makeSound(void) const{
	std::cout << "WrongCat " << _type << " say miaouuu!" << std::endl;
}
