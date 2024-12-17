/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/16 19:18:01 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */
 
#include "class/AMateria.hpp"
#include "class/Ice.hpp"
#include "class/Cure.hpp"
#include "class/Character.hpp"
#include <unistd.h>

int main(void)
{
	Character c1("fab");
	Character c2("stan");
	Character *tmp = new Character("ptdr");

	std::cout << std::endl;
	c1.equip(new Ice);
	c1.equip(new Cure);
	c1.equip(new Ice);
	c1.unequip(1);
	c1.unequip(0);
	c1.unequip(2);
	c1.equip(new Ice);
	c1.equip(new Ice);
	c1.equip(new Ice);
	tmp->equip(new Cure);
	c1.display_inv();
	c1.display_floor();
	std::cout << std::endl;
	std::cout << "awdawd" << std::endl;
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	// return 0;
}
