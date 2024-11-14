/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:35 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 17:13:31 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
