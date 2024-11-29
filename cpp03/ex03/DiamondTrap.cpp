/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:48:01 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/29 18:53:14 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() :
	ScavTrap("DiamondTrap"), FragTrap("DiamonTrap_clap_name"), _name("DiamiondTrap_clap_name"){
	ScavTrap::setValue(100, 50, 30);
	std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) :
	ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name){
	std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ScavTrap(other), FragTrap(other), _name(other._name){}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other){
	if (this != &other){
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target){ScavTrap::attack(target);}

void DiamondTrap::takeDamage(unsigned int amount){FragTrap::takeDamage(amount);}

void DiamondTrap::beRepaired(unsigned int amount){FragTrap::beRepaired(amount);}

std::string DiamondTrap::getName() const{return (ScavTrap::getName());}

unsigned int DiamondTrap::getHit() const{return (FragTrap::getHit());}

unsigned int DiamondTrap::getEnergy() const{return (ScavTrap::getEnergy());}

unsigned int DiamondTrap::getAttack() const{return (FragTrap::getAttack());}

void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ScavTrap::getName() << std::endl;
}
