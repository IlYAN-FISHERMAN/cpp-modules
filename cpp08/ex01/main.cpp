/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:22:37 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/24 15:16:13 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <cstdlib>
#include <exception>
#include <vector>

int main()
{
	{
		try{
			Span sp = Span(5);
			// for (int i = 0; i < 10; i++)
			// 	sp.addNumber(sp.generateNbr());
			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MIN);
			sp.addNumber(4);
			sp.addNumber(25);
			sp.addNumber(118);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		catch(const std::exception &other){
			std::cout << other.what() << std::endl;
		}
	}
	{
		try{
			Span sp(10);
			sp.fillNumber(sp.getTab().begin(), sp.getTab().end());
			for (size_t i = 0; i < sp.getTab().size(); i++)
				std::cout << sp[i] << std::endl;

			std::cout << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		catch(const std::exception &other){
			std::cout << other.what() << std::endl;
		}
	}
		{
			try{
				std::cout << std::endl;
				Span sp = Span(5);
				sp.addNumber(6);
				sp.addNumber(3);
				sp.addNumber(17);
				sp.addNumber(9);
				sp.addNumber(11);
				sp.addNumber(11);
				std::cout << sp.shortestSpan() << std::endl;
				std::cout << sp.longestSpan() << std::endl;
			}
			catch(const std::exception &other){
				std::cout << other.what() << std::endl;
			}
		}
	return 0;
}
