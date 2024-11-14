/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:10:02 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 21:22:41 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string weapon) : _type(weapon){
}

Weapon::~Weapon(){}

const std::string& Weapon::getType() const{
	return (_type);
}

void Weapon::setType(const std::string &str){
	_type = str;
}
