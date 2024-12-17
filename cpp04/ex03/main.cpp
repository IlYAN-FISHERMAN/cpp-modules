/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/15 10:19:56 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */
 
#include "class/Ice.hpp"
#include "class/Cure.hpp"
#include "class/Character.hpp"
#include "class/ICharacter.hpp"

int main(void)
{
	Character c1("fab");
	Character c2("stan");
	Cure	ex1;
	Ice		ex2;
	Cure	ex3;
	Ice		ex4;
	Ice		ex5;

	std::cout << std::endl;

	c1.equip(&ex1);
	c1.equip(&ex2);
	c1.equip(&ex3);
	c1.use(0, c2);
	c1.unequip(1);
	c1.unequip(0);
	c1.display_inv();
	c1.display_floor();
	std::cout << std::endl;
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
