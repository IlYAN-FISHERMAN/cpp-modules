/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:22:37 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/23 11:47:39 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <cstdlib>
#include <exception>
#include <vector>

int main()
{
	// {
		// try{
		// 	Span sp = Span(5);
		// 	// for (int i = 0; i < 10; i++)
		// 	// 	sp.addNumber(sp.generateNbr());
		// 	sp.addNumber(INT_MAX);
		// 	sp.addNumber(INT_MIN);
		// 	sp.addNumber(4);
		// 	sp.addNumber(25);
		// 	sp.addNumber(118);
		//
		// 	std::cout << sp.shortestSpan() << std::endl;
		// 	std::cout << sp.longestSpan() << std::endl;
		// }
		// catch(const std::exception &other){
		// 	std::cout << other.what() << std::endl;
		// }
	// }
	{
		try{
			Span sp(10);
			// std::vector<int> tmp(10);
			// std::cout << tmp.assign(10) << std::endl << std::endl;
			// tmp.at(0) = 10;
			// for (size_t i = 0; i < tmp.size() ;i++)
			// 	std::cout << tmp[i] << std::endl;
			// sp.getTab().push_back(42);
			// sp.getTab().push_back(42);
			// sp.getTab().resize(100);
			sp.fillNumber(sp.getTab().begin(), sp.getTab().end() - 5);
			sp.addNumber(100000);
			sp.addNumber(100000);
			sp.addNumber(100000);
			sp.addNumber(100000);
			sp.addNumber(100000);
			for (size_t i = 0; i < sp.getTab().size(); i++)
				std::cout << sp[i] << std::endl;

			std::cout << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
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
				std::cout << sp.shortestSpan() << std::endl;
				std::cout << sp.longestSpan() << std::endl;
			}
			catch(const std::exception &other){
				std::cout << other.what() << std::endl;
			}
		}
	return 0;
}
