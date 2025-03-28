/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:48 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/29 15:29:06 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"){}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack(0){
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	_name(other._name), _hit(other._hit), _energy(other._energy), _attack(other._attack){}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
	if (this != &other){
		_name = other._name;
		_hit = other._hit;
		_energy = other._energy;
		_attack = other._attack;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target){
	if (_hit <= 0)
		std::cout << "ClapTrap " << _name << " is dead and can't attack anyone" << std::endl;
	else if (_energy > 0){
		std::cout << "ClapTrap " << _name << " causes " << _attack << " damage to " << target << std::endl;
		_energy--;
	}
	else
		std::cout << "ClapTrap " << _name << " don't have enought Energy points to attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hit > 0){
		std::cout << "ClapTrap " << _name << " take " << amount << " points of damage" << std::endl;
		while (_hit > 0 && amount){
			amount--;
			_hit--;
		}
	}
	else
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_hit <= 0)
		std::cout << "ClapTrap " << _name << " is dead and can't repairs itself" << std::endl;
	else if (_energy > 0){
		std::cout << "ClapTrap " << _name << " repairs itself it gets " << amount << " hit points back" << std::endl;
		_hit += amount;
		_energy--;
	}
	else
		std::cout << "ClapTrap " << _name << " don't have enought Energy points for repairs itself" << std::endl;
}

std::string ClapTrap::getName() const{return (_name);}

unsigned int ClapTrap::getHit() const{return (_hit);}

unsigned int ClapTrap::getEnergy() const{return (_energy);}

unsigned int ClapTrap::getAttack() const{return (_attack);}

void	ClapTrap::decrementEnergy(){_energy--;}

void	ClapTrap::setValue(int hit, int energy, int attack){
	_hit = hit;
	_energy = energy;
	_attack = attack;
}
