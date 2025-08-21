/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:10:02 by ilyanar           #+#    #+#             */
/*   Updated: 2025/08/21 18:26:00 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const char *weapon) : _type(weapon){
}

Weapon::~Weapon(){}

const std::string& Weapon::getType() const{
	return (_type);
}

void Weapon::setType(const char *str){
	_type = std::string(str);
}
