/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:58:44 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/26 23:15:39 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// Mandatory
	std::cout << std::endl << "Mandatory tests" << std::endl << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl << std::endl;

	// My Tests
	std::cout << "My tests" << std::endl << std::endl;
	std::cout << "\033[032ma is: " << a << "  b is: " << b << "\033[0m" << std::endl << std::endl;
	if (a > b)
		std::cout << "a is > than b" << std::endl;
	else
		std::cout << "b is > than a" << std::endl;
	if (a < b)
		std::cout << "a is < than b" << std::endl;
	else
		std::cout << "b is < than a" << std::endl;
	if (a >= b)
		std::cout << "a is >= than b" << std::endl;
	else
		std::cout << "b is >= than a" << std::endl;
	if (a <= b)
		std::cout << "a is <= than b" << std::endl;
	else
		std::cout << "b is <= than a" << std::endl;
	if (a == b)
		std::cout << "a is == than b" << std::endl;
	if (a != b)
		std::cout << "a is != than b" << std::endl;
	std::cout << "\033[031ma is: " << a << "  b is: " << b << "\033[0m" << std::endl << std::endl;
	std::cout << "the smallest between a and b is: " << Fixed::min( a, b ) << std::endl;
	std::cout << "the greater between a and b is: " << Fixed::max( a, b ) << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / 0 << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	Fixed c(10);
	Fixed d(10.42f);
	if (a == c)
		std::cout << "a and c is egal" << std::endl;
	std::cout << "\033[032ma is: " << a << "  b is: " << b << "\033[0m" << std::endl << std::endl;
	std::cout << "c value = " << c.toFloat() << std::endl;
	std::cout << "d value = " << d.toFloat() << std::endl;
	std::cout << c * d << std::endl;
	return 0;
}
