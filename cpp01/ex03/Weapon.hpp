/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:56 by ilyanar           #+#    #+#             */
/*   Updated: 2025/08/21 18:23:42 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private :
		std::string	_type;

	public  :
		Weapon(const char *weapon);
		~Weapon();
		const std::string	&getType() const;
		void setType(const char *str);
};

#endif
