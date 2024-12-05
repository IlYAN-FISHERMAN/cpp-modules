/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:32:44 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/05 16:59:05 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain(std::string ideas[100]);
		Brain& operator=(const Brain &other);
		void	setIdeas(std::string idea[100]);
		void			printIdeas();
};

#endif
