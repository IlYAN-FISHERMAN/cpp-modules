/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:37:39 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/06 17:18:37 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "class/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "\033[31mBad format: \033[0monly one string accepted." << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
}
