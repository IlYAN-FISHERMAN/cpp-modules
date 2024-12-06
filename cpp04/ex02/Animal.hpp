/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:24:06 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/05 18:00:55 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		virtual ~Animal() =  0;
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		Animal(std::string type);

		virtual void makeSound(void) const;
		virtual const std::string &getType(void) const;
};

#endif
