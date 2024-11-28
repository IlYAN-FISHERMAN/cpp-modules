/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:41:54 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/28 16:33:36 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){}

ScavTrap::~ScavTrap(){}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
		std::cout << "ScavTrap " << other.getName() << " created" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
	if (this != &other)
		ClapTrap(operator=(other));
	return (*this);
}

void ScavTrap::guardGate() const{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (getEnergy() > 0){
		std::cout << "ScavTrap " << getName() << " causes " << getAttack() << " damage to " << target << std::endl;
		decrementEnergy();
	}
	else
		std::cout << "ScavTrap " << getName() << " don't have enought Energy points" << std::endl;
}
