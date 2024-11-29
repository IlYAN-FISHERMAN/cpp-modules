/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:41:54 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/29 14:31:54 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ClapTrap"){}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){setValue(100, 50, 20);}

ScavTrap::~ScavTrap(){}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
		std::cout << "ScavTrap " << other.getName() << " created" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

void ScavTrap::guardGate() const{
	if (getHit() <= 0)
		std::cout << "ScavTrap " << getName() << " is dead and can't be in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (getHit() <= 0)
		std::cout << "ScavTrap " << getName() << " is dead and can't attack anyone" << std::endl;
	else if (getEnergy() > 0){
		std::cout << "ScavTrap " << getName() << " causes " << getAttack() << " damage to " << target << std::endl;
		decrementEnergy();
	}
	else
		std::cout << "ScavTrap " << getName() << " don't have enought Energy points" << std::endl;
}
