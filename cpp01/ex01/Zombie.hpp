/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:35 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 18:40:16 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string _name;
		int			_index;

	public:
		Zombie(void);
		~Zombie(void);
		void 	announce(void);
		void	setZombie(std::string &name, int index);
};

Zombie* zombieHorde( int N, std::string name );

#endif
