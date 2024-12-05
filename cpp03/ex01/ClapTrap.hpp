/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:36:50 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/03 19:14:54 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string 	_name;
		unsigned int 	_hit;
		unsigned int	_energy;
		unsigned int	_attack;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);

		void 			attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		std::string 	getName() const;
		unsigned int 	getHit() const;
		unsigned int 	getEnergy() const;
		unsigned int 	getAttack() const;
		void			decrementEnergy();
		void			setValue(int hit, int energy, int attack);
};

#endif
