/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/17 18:53:11 by ilyanar          ###   LAUSANNE.ch       */
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
