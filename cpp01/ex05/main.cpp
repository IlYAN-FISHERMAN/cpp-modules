/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:12:36 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/15 13:58:46 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Bad number of arg" << std::endl << std::endl;
		std::cerr << "    Usage: ./reverse <LEVEL>" << std::endl;
		return (1);
	}
	Harl	harl_level;
	harl_level.complain(av[1]);
}
