/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:56:55 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/21 17:50:16 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <set>
#include <vector>

int	main()
{
	std::vector<int>	nbr;

	nbr.push_back(-42);
	nbr.push_back(10);
	nbr.push_back(1);
	nbr.push_back(0);
	nbr.push_back(313151);
	nbr.push_back(46362525);
	try{
		std::cout << easyfind(nbr, -42) << std::endl;
		std::cout << easyfind(nbr, 10) << std::endl;
		std::cout << easyfind(nbr, 1) << std::endl;
		std::cout << easyfind(nbr, 46362525) << std::endl;
		std::cout << easyfind(nbr, 100) << std::endl;
	}
	catch (const char *error){
		std::cout << error << std::endl;
	}
}
