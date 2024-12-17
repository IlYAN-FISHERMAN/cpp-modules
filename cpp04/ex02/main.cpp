/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/13 23:01:08 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
	Dog a("fab the dogydogy");
	Cat b("maria the kitty");
	// Animal tmp;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = new Cat();
	// const Animal* j = new Animal();

	i = k;
	std::cout << std::endl;
	a.makeSound();
	b.makeSound();
	i->makeSound();
	std::cout << std::endl << a.getType() << std::endl << b.getType() << std::endl;
	// a.printIdeas();
	// b.printIdeas();
	delete j;
	delete i;
	(void)k;
}
