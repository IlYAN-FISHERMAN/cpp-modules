/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:31:02 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 21:23:32 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon weapon){
	_weapon = weapon;
}

void	HumanB::attack(void){
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
