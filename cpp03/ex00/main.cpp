/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:49 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/29 12:10:22 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("fabien");
	ClapTrap b("maria");

	std::cout << std::endl;
	for(int i = 0; i <= 11; i++)
		a.attack("maria");
	std::cout << std::endl;
	b.takeDamage(10);
	b.takeDamage(10);
	b.beRepaired(20);
	b.attack("stan");
	a.takeDamage(5000);
	a.beRepaired(10);
	std::cout << std::endl;
}
