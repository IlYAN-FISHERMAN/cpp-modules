/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:14:03 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/28 16:52:49 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap& operator=(const FragTrap &other);
};

#endif
