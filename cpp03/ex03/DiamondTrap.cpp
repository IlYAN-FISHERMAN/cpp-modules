/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:48:01 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/04 22:39:42 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamiondTrap_clap_name"){
	setValue(100, 50, 30);
	std::cout << "Default diamondTrap created" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name){
	setValue(100, 50, 30);
	std::cout << "DiamondTrap " << _name << " created" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
ClapTrap(other.getName()), _name(other._name){}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other){
	if (this != &other){
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

const std::string& DiamondTrap::getName() const{return (_name);}

void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ScavTrap::getName() << std::endl << std::endl;
}

void DiamondTrap::magicExplosion(DiamondTrap &other){
	if (this->getHit() <= 0)
		std::cout << getName() << " is dead and can't use magic spell" << std::endl;
	else if (this->getEnergy() <= 0)
		std::cout << getName() << " don't have enought energy and can't use magic spell" << std::endl;
	else
	{
		std::cout << getName()
			<< " use the MAGIC EXPLOSION and burns all the power he left to instant kill "
			<< other.getName() << std::endl;
		other.takeDamage(other.getHit() * 10);
		this->_energy = 0;
	}
}

void DiamondTrap::anihilation(DiamondTrap &other){
	if (this->getHit() <= 0)
		std::cout << getName() << " is dead and can't use magic spell" << std::endl;
	else if (this->getEnergy() <= 0)
		std::cout << getName() << " don't have enought energy and can't use magic spell" << std::endl;
	else
	{
		std::cout << getName()
			<< " kill itself in a autodestruction and instant kill "
			<< other.getName() << std::endl;
		other.setValue(0, 0, other.getAttack());
		setValue(0, 0, getAttack());
		std::cout << getName() << " and " <<
			other.getName() << " are dead" << std::endl;
	}
}
