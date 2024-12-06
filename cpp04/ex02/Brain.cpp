/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:33:52 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/05 17:03:49 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _ideas(){
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other){
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain &other){
	if (this != &other)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	return (*this);
}

void Brain::setIdeas(std::string idea[100]){
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea[i];
}

void Brain::printIdeas(){
	for (int i = 0; i < 100; i++)
		std::cout << _ideas[i] << std::endl;
	std::cout << std::endl;
}
