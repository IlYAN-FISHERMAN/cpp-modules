/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:03:23 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 21:19:20 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private :
		Weapon		_weapon;
		std::string	_name;

	public :
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon weapon);
};

#endif
