/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:23:35 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/15 18:07:15 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVENTORY_HPP
# define INVENTORY_HPP

#include "../class/AMateria.hpp"

class Inv
{
	protected:
		AMateria *_m;
		bool	 _is_equiped;
	public:
		Inv();
		~Inv();
		Inv(AMateria *m);
		Inv(const Inv &other);
		Inv &operator=(const Inv &other);

		void 		setM(AMateria *m);
		void 		setEquip(bool is_equiped);

		const AMateria			*getM() const;
		AMateria				*getMCopy() const;
		bool 					getEquip() const;
		const std::string 		getType() const;

		void use(ICharacter& target);
		void 		destroyM();
};

#endif
