/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:07:26 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/12 18:09:01 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &other);
		Cure(const std::string name);
		Cure& operator=(const Cure &other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif // !CURE_HPP
