/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:52:48 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/17 18:41:49 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "../class/IMateriaSource.hpp"
#include "../class/Inventory.hpp"
#include "../class/Character.hpp"
#include "../class/AMateria.hpp"

class MateriaSource : public IMateriaSource, public Inv
{
	private:
		Inv _inv[4];
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
