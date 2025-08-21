/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:03:23 by ilyanar           #+#    #+#             */
/*   Updated: 2025/08/21 18:08:56 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private :
		Weapon& _weapon;
		const char *_name;

	public :
		HumanA(const char *name, Weapon &weapon);
		~HumanA();
		void	attack();
};

#endif
