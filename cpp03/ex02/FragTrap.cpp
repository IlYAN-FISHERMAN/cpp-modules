/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:14:37 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/28 16:51:10 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap " << getName() << " created" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << getName() << " destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){}

FragTrap& FragTrap::operator=(const FragTrap &other){
	if (this != &other)
		ClapTrap(operator=(other));
	return (*this);
}
