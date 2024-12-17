/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:54:25 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/17 18:52:51 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource default constructor" << std::endl;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource default destructor" << std::endl;
	for (int i = 0; i < MAX_INV; i++)
		if (_inv[i].getEquip())
			_inv[i].destroyM();
}

void MateriaSource::learnMateria(AMateria* m){
	if (!m){
		std::cerr << "Error: no Materia gived to learnMateria function" << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_INV + 1; i++){
		if (i >= MAX_INV){
			std::cout << "The materiaSource inventory is full !" << std::endl;
			return ;
		}
		if (!_inv[i].getEquip()){
			_inv[i].setM(m->clone());
			_inv[i].setEquip(true);
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < MAX_INV + 1; i++){
		if (i >= MAX_INV){
			std::cout << "No " << type << " founded in the inventory" << std::endl;
			break ;
		}
		else if (_inv[i].getType() == type)
			return (_inv[i].getMCopy());
	}
	return (NULL);
}
