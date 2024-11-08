/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:47:31 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/04 14:53:05 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	for (int i = 1; ac > 1 && i < ac; i++)
		for (int d = 0; av[i][d]; d++)
			std::cout << (char)std::toupper(av[i][d]);
	(ac < 2) ? std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" : std::cout;
	std::cout << std::endl;
}
