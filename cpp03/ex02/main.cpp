/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:49 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/28 12:12:09 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("fabien");
	ScavTrap b("maria");

	std::cout << std::endl;
	for(int i = 0; i <= 5; i++){
		a.attack(b.getName());
		b.takeDamage(a.getAttack());
		std::cout << std::endl;
	}
	b.beRepaired(20);
	b.attack(a.getName());
	a.takeDamage(5000);
	std::cout << std::endl;
	std::cout << std::endl;
	a.guardGate();
	b.guardGate();
	std::cout << std::endl;
}
