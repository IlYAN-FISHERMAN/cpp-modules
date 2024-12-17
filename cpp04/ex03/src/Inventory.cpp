/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:26:44 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/17 13:53:27 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Inventory.hpp"

Inv::Inv() : _m(NULL), _is_equiped(false){}

Inv::~Inv(){}

Inv::Inv(AMateria *m) : _m(m), _is_equiped(true){}

Inv::Inv(const Inv &other) : _m(other._m->clone()), _is_equiped(other._is_equiped){}

Inv& Inv::operator=(const Inv &other){
	if (this != &other){
		_m = other._m;
		_is_equiped = other._is_equiped;
	}
	return (*this);
}

void Inv::setM(AMateria *m){ _m = m;}

void Inv::setEquip(bool is_equiped){ _is_equiped = is_equiped;}

void Inv::destroyM(){
	delete _m;
	_m = NULL;
}

const AMateria* 	Inv::getM() const{return (_m);}

AMateria* 	Inv::getMCopy() const{return (_m->clone());}

bool 		Inv::getEquip() const{return (_is_equiped);}

const std::string 		Inv::getType() const{
	if (_is_equiped)
		return (_m->getType());
	else
		return ("No Materia");
}

void Inv::use(ICharacter& target){_m->use(target);}
