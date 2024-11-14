/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:50:39 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 18:46:02 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::setZombie(std::string &name, int index){
	_name = name;
	_index = index;
}

Zombie* zombieHorde(int N, std::string name){
	Zombie *newZombieHorde = new Zombie[N];

	for (int d = 0; d < N; d++)
		newZombieHorde[d].setZombie(name, d);
	return (newZombieHorde);
}
