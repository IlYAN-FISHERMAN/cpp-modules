/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:03:23 by ilyanar           #+#    #+#             */
/*   Updated: 2025/08/21 18:09:03 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private :
		Weapon*	_weapon;
		const char * _name;

	public :
		HumanB(const char *name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weapon);
};

#endif
