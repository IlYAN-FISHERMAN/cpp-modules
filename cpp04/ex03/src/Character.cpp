/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:15:21 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/09 15:34:15 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Character.hpp"

Character::Character(){
}

Character::~Character(){
}

Character::Character(Character const & src){
}

Character::Character(std::string const & name){
}

std::string const & Character::getName() const{
}

void Character::equip(AMateria* m){
}

void Character::unequip(int idx){
}

void Character::use(int idx, ICharacter& target){
}
