/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:49 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/04 22:38:55 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	fight1(DiamondTrap &a, DiamondTrap &b)
{
	std::cout << std::endl; 
	
	std::cout << "the fight between " << a.getName() << " and " << b.getName() << " BEGINS !!!" << std::endl;
	a.attack(b.getName());
	std::cout << "\033[031mOMG " << a.getName() << " attack "<< b.getName() << " with " << a.getAttack() << " Dommage!\033[0m" << std::endl;
	b.takeDamage(a.getAttack());
	b.beRepaired(10);
	a.magicExplosion(b);
	std::cout << std::endl;
}

void	fight2(DiamondTrap &a, DiamondTrap &b)
{
	std::cout << std::endl; 
	b.anihilation(a);
	std::cout << std::endl;
}

static void final_marks(DiamondTrap &a, DiamondTrap &b, DiamondTrap &c){
	std::cout << "\033[032m╔═══════════FINAL SCORE═══════════╗" << std::endl;
	std::cout << "\033[032m║ \033[032m Fighter 1 :" << std::endl;
	std::cout << "\033[032m║ \033[034m  " << b.getName() << std::endl;
	std::cout << "\033[032m║ \033[034m  " << b.getHit() << std::endl;
	std::cout << "\033[032m║ \033[034m  " << b.getEnergy() << std::endl;
	std::cout << "\033[032m║ \033[034m  " << b.getAttack() << std::endl;
	std::cout << "\033[032m║ \033[034m " << std::endl; 
	std::cout << "\033[032m║ \033[032m Fighter 2 :" << std::endl;
	std::cout << "\033[032m║ \033[034m  " << a.getName() << std::endl;
	std::cout << "\033[032m║ \033[034m  " << a.getHit() << std::endl;
	std::cout << "\033[032m║ \033[034m  " << a.getEnergy() << std::endl;
	std::cout << "\033[032m║ \033[034m  " << a.getAttack() << std::endl;
	std::cout << "\033[032m║" << std::endl; 
	std::cout << "\033[032m║ \033[032m Fighter 3 :" << std::endl;
	std::cout << "\033[032m║ \033[034m  " << c.getName() << std::endl;
	std::cout << "\033[032m║ \033[034m  " << c.getHit() << std::endl;
	std::cout << "\033[032m║ \033[034m  " << c.getEnergy() << std::endl;
	std::cout << "\033[032m║ \033[034m  " << c.getAttack() << std::endl;
	std::cout << "\033[032m╚═════════════════════════════════" << std::endl;
	std::cout << "\033[0m";
}

int main(void)
{
	DiamondTrap a("rui");
	DiamondTrap b("stan");
	DiamondTrap c("fab");
	DiamondTrap d("cecile");

	fight1(a, b);
	fight2(a, c);
	final_marks(a, b, c);
	std::cout << std::endl;
	b.highFivesGuys();
	a.highFivesGuys();
	d.highFivesGuys();
	std::cout << std::endl;
	a.whoAmI();
	b.whoAmI();
	d.whoAmI();
	std::cout << std::endl;
}
