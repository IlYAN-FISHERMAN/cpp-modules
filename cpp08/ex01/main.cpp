/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:22:37 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/21 21:11:16 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

int main()
{
	Span sp = Span(5);
	sp.addNumber(INT_MIN);
	sp.addNumber(4);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(110);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
