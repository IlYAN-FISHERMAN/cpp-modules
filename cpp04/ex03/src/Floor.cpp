/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:26:44 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/17 14:01:02 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Floor.hpp"
#include "../class/Inventory.hpp"

Floor::Floor() : _m(NULL), _is_equiped(false), _next(NULL){}

Floor::~Floor(){}

Floor::Floor(AMateria *m) : _m(m->clone()), _is_equiped(true),  _next(NULL){}

Floor::Floor(const Floor &other) : _m(other._m->clone()), _is_equiped(other._is_equiped), _next(NULL){}

Floor::Floor(const Floor *other) : _m(other->_m->clone()), _is_equiped(other->_is_equiped), _next(NULL){}

Floor::Floor(Inv &other) : _m(other.getMCopy()), _is_equiped(false), _next(NULL){}

Floor& Floor::operator=(const Floor &other){
	if (this != &other){
		_m = other._m->clone();
		_is_equiped = other._is_equiped;
		_next = other._next;
	}
	return (*this);
}
void Floor::setM(AMateria *m){ _m = m;}

void Floor::setNext(Floor *next){ _next = next;}

void Floor::setEquip(bool is_equiped){ _is_equiped = is_equiped;}

void Floor::destroyAll(){
	Floor *tmp = this->_next;
	Floor *tmp2;

	while(tmp){
		tmp2 = tmp;
		tmp = tmp->_next;
		delete tmp2->_m;
		delete tmp2;
	}
	delete _m;
	delete this;
}

void Floor::destroyM(){
	delete _m;
	_m = NULL;
}

const AMateria*	Floor::getM() const{return (_m);}

AMateria*	Floor::getMCopy() const{return (_m->clone());}

bool	Floor::getEquip() const{return (_is_equiped);}

Floor*	Floor::getNext() const{return (_next);}

const std::string 		Floor::getType() const{return (_m->getType());}
