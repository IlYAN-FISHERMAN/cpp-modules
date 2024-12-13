/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:07:53 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/12 18:55:07 by ilyanar          ###   LAUSANNE.ch       */
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
	struct s_inv 	*next;
	struct s_inv 	*prev;
} t_inv;

class Character : public ICharacter
{
	private:
		std::string _name;
		t_inv		*_inv;
		t_inv		*_floor;
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

};
#endif
