/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:22:28 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 18:50:21 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int	main(void)
{
	Zombie *zomb;
	int	N = 100;
	zomb = zombieHorde(N, "Cecile");

	for (int d = 0; d < N; d++){
		zomb[d].announce();
	}
	delete[] zomb;
	return (0);
}
