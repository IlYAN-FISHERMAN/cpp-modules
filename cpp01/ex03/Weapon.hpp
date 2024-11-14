/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:56 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 21:22:49 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private :
		std::string _type;

	public  :
		Weapon(const std::string weapon = "Epeenice");
		~Weapon();
		const std::string	&getType() const;
		void setType(const std::string &str);
};

#endif
