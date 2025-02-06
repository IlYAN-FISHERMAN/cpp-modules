/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:07:50 by ilyanar           #+#    #+#             */
/*   Updated: 2025/02/03 16:55:53 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>

int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Usage: ./PmergeMe \"1 94 42 323 424\"" << std::endl;
		return 1;
	}
	try{
		VectSort list1(av[1]);
		ListSort list2(av[1]);

		list1.sort();
		list2.sort();
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
