/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:54:10 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 18:46:34 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("DEFAULT"){
	std::cout << "Zombie created !" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << "Zombie " + _name + " with index:" << _index << " Destroyed" << std::endl;
}

void Zombie::announce(void){
	std::cout << "Zombie " + _name + " with index:"
		<< _index << " Say: " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
