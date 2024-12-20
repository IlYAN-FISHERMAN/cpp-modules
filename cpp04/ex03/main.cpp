/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/17 20:01:29 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */
 
#include "class/AMateria.hpp"
#include "class/Ice.hpp"
#include "class/Cure.hpp"
#include "class/Character.hpp"
#include "class/MateriaSource.hpp"

int main(void)
{
	Ice givrali("glace");
	Cure nymphali("fee");
	Cure nymphali2("fee");
	Cure nymphali3("fee");
	Cure nymphali4("fee");

	for (int i = 0; i < 4; i++)
	{
		src->learnMateria(&nymphali);
	}
	src->learnMateria(&nymphali2);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(&givrali);
	src->learnMateria(&nymphali);
	src->learnMateria(&givrali);
	src->learnMateria(&nymphali);
	src->learnMateria(&givrali);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
