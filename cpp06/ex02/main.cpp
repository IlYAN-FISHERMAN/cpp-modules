/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:41:28 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/08 22:17:26 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Base.hpp"
#include "class/A.hpp"
#include "class/B.hpp"
#include "class/C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base* generate(void)
{
	int	nb = rand() % 3;
	switch (nb) {
		case (0):
			std::cout << "A class created" << std::endl;
			return (new A);
			break;
		case (1):
			std::cout << "B class created" << std::endl;
			return (new B);
			break;
		case (2):
			std::cout << "C class created" << std::endl;
			return (new C);
			break;
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It's a A pointer class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's a B pointer class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's a C pointer class" << std::endl;
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "It's a A reference class" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "It's a B reference class" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "It's a C reference class" << std::endl;
}

int main(void)
{
	srand(time(0));
	Base *tmp1;
	Base *tmp2;
	Base *tmp3;

	tmp1 = generate();
	tmp2 = generate();
	tmp3 = generate();
	std::cout << std::endl;

	identify(tmp1);
	identify(tmp2);
	identify(tmp3);
	std::cout << std::endl;

	identify(*tmp1);
	identify(*tmp2);
	identify(*tmp3);
	std::cout << std::endl;

	delete tmp1;
	delete tmp2;
	delete tmp3;
}
