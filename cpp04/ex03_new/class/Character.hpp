/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:07:53 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/15 18:07:21 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "../class/Inventory.hpp"
# include "../class/Floor.hpp"

# define MAX_INV 4

class Character : public ICharacter
{
	private:
		std::string _name;
		Inv			_inv[4];
		Floor		*_floor;
	public:
		Character(std::string const &name);
		Character(const Character &other);
		Character& operator=(const Character &other);
		~Character();

		std::string const & getName() const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void display_inv();
		void display_floor();
};
#endif
