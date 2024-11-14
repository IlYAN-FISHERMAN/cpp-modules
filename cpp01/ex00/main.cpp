/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:22:28 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 17:28:31 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *pierre;
	Zombie tmp("cecile");

	pierre = newZombie("pierre");
	if (!pierre){
		std::cout << "new failed" << std::endl;
		return (1);
	}
	pierre->announce();
	tmp.announce();
	delete (pierre);
	return (0);
}
