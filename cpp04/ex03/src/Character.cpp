/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:15:21 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/17 14:15:52 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Character.hpp"

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
	
	for (int i = 0; i < MAX_INV; i++)
		if (_inv[i].getEquip())
			_inv[i].destroyM();
	if (_floor)
		_floor->destroyAll();
}

Character::Character(std::string const & name) : _name(name), _floor(NULL){
	std::cout << "Character string constructor called" << std::endl;
}

Character::Character(Character const & src) : _name(src._name), _floor(NULL){
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < MAX_INV; i++){
		_inv[i].setM(src._inv[i].getMCopy());
		_inv[i].setEquip(src._inv[i].getEquip());
	}
	if (src._floor)
	{
		_floor = new Floor(src._floor);
		for (Floor *tmp_old =  src._floor->getNext(), tmp_new = _floor; tmp_old; tmp_old = tmp_old->getNext())
			tmp_new.setNext(new Floor(tmp_old->getMCopy()));
	}
}

Character& Character::operator=(const Character &other){
	std::cout << "Character overload= operator called" << std::endl;
	if (this != &other){
		this->_name = other._name;
		for (int i = 0; i < MAX_INV; i++){
			if (other._inv[i].getEquip() && other._inv[i].getM()){
				_inv[i].destroyM();
				_inv[i].setM(other._inv[i].getMCopy());
				_inv[i].setEquip(other._inv[i].getEquip());
			}
		}
		if (other._floor){
			if (_floor)
				this->_floor->destroyAll();
			_floor = new Floor(other._floor);
			Floor *lst_old = other._floor;
			Floor *lst_new = _floor;
			while (lst_old->getNext()){
				lst_new->setNext(new Floor(lst_old->getNext()));
				lst_old = lst_old->getNext();
				lst_new = lst_new->getNext();
			}
		}
		else if (_floor)
			this->_floor->destroyAll();
	}
	return (*this);
}

std::string const & Character::getName() const{return (_name);}

void Character::equip(AMateria* m){
	for (int i = 0; i < MAX_INV + 1; i++){
		if (i == MAX_INV){
			std::cout << "The inventory is full" << std::endl;
			return ;
		}
		else if (!_inv[i].getEquip()){
			_inv[i].setM(m);
			_inv[i].setEquip(true);
			std::cout << _name << " equip " << m->getType() << std::endl;
			break ;
		}
	}
}

void Character::unequip(int idx){

	if (idx < 0 || idx > 3){
		std::cout << "\033[031m[Error]\033[0m bad idx number" << std::endl;
		return ;
	}
	else if (!_inv[idx].getEquip() || !_inv[idx].getM())
		std::cout << "\033[031m[Error]\033[0m no material at this idx" << std::endl;
	else{
		std::cout << _name << " unequip " << _inv[idx].getType() << std::endl;
		if (!_floor)
			_floor = new Floor(_inv[idx].getMCopy());
		else
		{
			Floor* new_node = _floor;
			while (new_node->getNext())
				new_node = new_node->getNext();
			new_node->setNext(new Floor(_inv[idx].getMCopy()));
		}
		_inv[idx].destroyM();
		_inv[idx].setEquip(false);
	}
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3){
		std::cout << "\033[031m[Error]\033[0m bad idx number" << std::endl;
		return ;
	}
	else if (!_inv[idx].getEquip() || !_inv[idx].getM())
		std::cout << "\033[031m[Error]\033[0m no _m at this idx" << std::endl;
	else
		_inv[idx].use(target);
}

void Character::display_floor(){
	Floor	*tmp;

	tmp = _floor;
	std::cout << "-- " + _name << " FLOOR --" << std::endl << std::endl;
	for (int i = 0; tmp; i++){
		std::cout << "╔════════════════════════════════╗" << std::endl;
		std::cout << "║                         " << i << std::endl;
		std::cout << "║ _m          : " << tmp->getType() << std::endl;
		std::cout << "║ _m addr     : " << tmp->getM() << std::endl;
		std::cout << "║ Is_equiped  : " << tmp->getEquip() << std::endl;
		std::cout << "║ Next        : " << tmp->getNext() << std::endl;
		std::cout << "╚════════════════════════════════╝" << std::endl << std::endl;
		tmp = tmp->getNext();
	}
	std::cout << std::endl;
}

void Character::display_inv(){
	std::cout << "-- " + _name << " INVENTORY --" << std::endl << std::endl;
	for (int i = 0; i < MAX_INV; i++){
		std::cout << "╔═════════════════════════════╗" << std::endl;
		std::cout << "║                         " << i << std::endl;
		if (_inv[i].getEquip())
			std::cout << "║ _m       : " << _inv[i].getType() << std::endl;
		else
			std::cout << "║ _m    :  empty" << std::endl;
		std::cout << "║ _m add   : " << _inv[i].getM() << std::endl;
		std::cout << "║ Is_equiped : " << _inv[i].getEquip() << std::endl;
		std::cout << "╚═════════════════════════════╝" << std::endl << std::endl;
	}
	std::cout << std::endl;
}
