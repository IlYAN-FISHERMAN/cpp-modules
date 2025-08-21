/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:29:11 by ilyanar           #+#    #+#             */
/*   Updated: 2025/08/21 18:06:05 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const char *name, Weapon &weapon) : _weapon(weapon), _name(name){}

HumanA::~HumanA(){}

void	HumanA::attack(void){
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
