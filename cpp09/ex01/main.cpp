/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:24:53 by ilyanar           #+#    #+#             */
/*   Updated: 2025/02/02 15:37:59 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Usage: ./RPN \"1 2 * 3 - 4 *\"" << std::endl;
		return 1;
	}
	try{
		Rpn rpn(av[1]);
		if (DEBUG)
			rpn.showStack();
		rpn.calculeStack();
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
