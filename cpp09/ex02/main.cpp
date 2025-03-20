/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:07:50 by ilyanar           #+#    #+#             */
/*   Updated: 2025/03/20 14:40:42 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>


int main(int ac, char **av)
{
	if (!DEBUG && ac != 2){
		std::cerr << "Usage: " + std::string(av[0]) + " \"1 94 42 323 424\"" << std::endl;
		return -1;
	}
	else if (DEBUG && (ac != 2 && ac != 3)){
		std::cerr << "Usage: " + std::string(av[0]).append("[DEBUG] ") + "\"1 94 42 323 424\" [DEBUG_MODE: 1,2,3]" << std::endl;
		return -1;
	}
	try{
		long nb = 0;
		if (ac == 3 && DEBUG){
			char *tmp = NULL;
			nb = strtol(av[2], &tmp, 10);
			if (*tmp || (nb < 0 || nb > 3)){
				std::cerr << "Usage: " + std::string(av[0]).append("[DEBUG] ") + "\"1 94 42 323 424\" [DEBUG_MODE: 1,2,3]" << std::endl;
				return -1;
			}
		}
		VectSort list1(av[1]);
		DequeSort list2(av[1]);

		if (ac == 3 && DEBUG){
			list1.setDebug(nb);
			list2.setDebug(nb);
		}
		list1.FordJonhson();
		std::cout << std::endl;
		list2.FordJonhson();
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
