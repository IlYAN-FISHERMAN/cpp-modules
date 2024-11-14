/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:03:23 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 21:19:02 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private :
		Weapon		_weapon;
		std::string	_name;

	public :
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		void	attack();
};

#endif
