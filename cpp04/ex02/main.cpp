/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:15 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/12 16:51:14 by ilyanar          ###   LAUSANNE.ch       */
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
	// const Animal* j = new Animal();

	std::cout << std::endl;
	a.makeSound();
	b.makeSound();
	std::cout << std::endl << a.getType() << std::endl << b.getType() << std::endl;
	i = j;
	// a.printIdeas();
	// b.printIdeas();
	delete j;
	(void)i;
}
