/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:22:37 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/21 22:08:29 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <cstdlib>

int main()
{
	srand(time(0));

	Span sp = Span(5);
	// for (int i = 0; i < 10; i++)
	// 	sp.addNumber(rand());
	sp.addNumber(INT_MAX);
	sp.addNumber(4);
	sp.addNumber(25);
	sp.addNumber(INT_MIN);
	sp.addNumber(118);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
