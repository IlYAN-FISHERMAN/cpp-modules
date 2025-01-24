/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:56:55 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/24 14:33:00 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <iterator>

int	main()
{
	std::vector<int>	nbr;

	nbr.push_back(1);
	nbr.push_back(10);
	nbr.push_back(42);
	nbr.push_back(42424);
	nbr.push_back(313151);
	nbr.push_back(46365);
	try{
		std::cout << easyfind(nbr, 313151) << std::endl;
		std::cout << easyfind(nbr, 46365) << std::endl;
		std::cout << easyfind(nbr, 1) << std::endl;
		std::cout << easyfind(nbr, 10) << std::endl;
		std::cout << easyfind(nbr, 42) << std::endl;
		std::cout << easyfind(nbr, 10000000) << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
