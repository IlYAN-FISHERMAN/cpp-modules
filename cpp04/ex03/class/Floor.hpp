/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:23:35 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/15 12:22:57 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "../class/AMateria.hpp"
#include "../class/Inventory.hpp"

class Floor{
	protected:
		AMateria *_m;
		bool	 _is_equiped;
		Floor	 *_next;
	public:
		Floor();
		~Floor();
		Floor(AMateria *m);
		Floor(const Floor &other);
		Floor(const Floor *other);
		Floor(Inv &other);
		Floor &operator=(const Floor &other);

		void 			setM(AMateria *m);
		void 			setEquip(bool is_equiped);
		void 			setNext(Floor *next);

		const AMateria 	*getM() const;
		AMateria 		*getMCopy() const;
		bool 			getEquip() const;
		Floor*	 		getNext() const;
		const std::string 		getType() const;

		void 			destroyM();
		void 			destroyAll();
};

#endif
