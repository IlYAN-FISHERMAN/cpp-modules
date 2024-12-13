/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:07:53 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/13 18:48:14 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define MAX_INV 4

typedef struct s_inv
{
	AMateria 		*materia;
	bool 			is_equiped;
} t_inv;

typedef struct s_flor
{
	AMateria 		*materia;
	bool 			is_equiped;
	struct s_flor 	*next;
} t_flor;

class Character : public ICharacter
{
	private:
		std::string _name;
		t_inv		_inv[4];
		t_flor		*_floor;
		int			_size;
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
