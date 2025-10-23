/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:07:50 by ilyanar           #+#    #+#             */
/*   Updated: 2025/10/23 12:13:58 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>

void printUsage(const char *av, int option = 0){
	
	if (option == 0){
		std::cout << "Usage:" << std::endl;
		std::cout << av << " \"positive numbers... \"" << std::endl << std::endl;
		std::cout << std::endl;

		std::cout << "META OPTIONS" << std::endl;
		std::cout << "  --help\tshow list of command-line options" << std::endl;
		std::cout << std::endl;

		std::cout << "Numbers" << std::endl;
		std::cout << "  Only positive numbers is accepted" << std::endl;
		std::cout << std::endl;

		std::cout << "DEBUG" << std::endl;
		std::cout << "  You can try debug mode with: \"make debug && \"" << av << " --help" << std::endl;
		std::cout << std::endl;

		std::cout << std::endl;
	} else if (option == 1){
		std::cout << "Usage:" << std::endl;
		std::cout << av << " \"positive numbers... \" [debug level]" << std::endl << std::endl;
		std::cout << std::endl;

		std::cout << "META OPTIONS" << std::endl;
		std::cout << "  --help\tshow list of command-line options" << std::endl;
		std::cout << std::endl;

		std::cout << "DEBUG LEVEL" << std::endl;
		std::cout << "  0, empty \tIf no level is specified you will see all possible debugs" << std::endl;
		std::cout << "  1, \t\tShow the merge part of Ford-Johnson" << std::endl;
		std::cout << "  2, \t\tShow the insert-sort part of Ford-Johnson (include the binary search and jacobsthal)" << std::endl;
		std::cout << "  3, \t\tSkip debug mode and display the result directly" << std::endl;
		std::cout << std::endl;
	}
}

int main(int ac, char **av)
{
	if ((ac < 2 || ac > 3) || (!DEBUG && ac > 2)){
		if (DEBUG)
			std::cerr << "Usage: " << av[0] << "[DEBUG] \"1 94 42 323 424\" [DEBUG_MODE: 1,2,3]" << std::endl;
		else
			std::cerr << "Usage: " << av[0] << " 8 568 9 426 4 724 424" << std::endl;
		std::cerr << "Try " << av[0] <<  " --help" << std::endl;
		return 0;
	}
	else if (ac == 2 && !strcmp(av[1], "--help")){
		if (DEBUG)
			printUsage(av[0], 1);
		else
			printUsage(av[0]);
		return 0;
	}
	try{
		long nb = 0;
		if (ac == 3 && DEBUG){
			char *tmp = NULL;
			nb = strtol(av[2], &tmp, 10);
			if (*tmp || (nb < 0 || nb > 3)){
				std::cerr << "Usage: " << av[0] << "[DEBUG] \"1 94 42 323 424\" [DEBUG_MODE: 1,2,3]" << std::endl;
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
		return 1;
	}
}
