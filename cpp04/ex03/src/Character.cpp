/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:15:21 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/13 11:26:55 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Character.hpp"
#include <cmath>

Character::~Character(){
	t_inv	*tmp1;

	std::cout << "Character destructor called" << std::endl;
	while (this->_inv){
		tmp1 = this->_inv;
		this->_inv = this->_inv->next;
		delete tmp1;
	}
	while (this->_floor){
		tmp1 = this->_floor;
		this->_floor = this->_inv->next;
		delete tmp1;
	}
}

Character::Character(std::string const & name) : _name(name), _inv(NULL), _floor(NULL), _size(0){}

Character::Character(Character const & src) : _name(src._name), _inv(NULL), _floor(NULL), _size(src._size){
	t_inv *tmp1;
	t_inv **tmp2;

	tmp1 = src._inv;
	tmp2 = &this->_inv;
	while (tmp1){
		*tmp2 = new t_inv;
		(*tmp2)->materia = tmp1->materia->clone();
		(*tmp2)->is_equiped = tmp1->is_equiped;
		(*tmp2)->next = tmp1->next;
		(*tmp2)->prev = tmp1->prev;
		(*tmp2) = (*tmp2)->next;
		tmp1 = tmp1->next;
	}
	tmp1 = src._floor;
	tmp2 = &this->_floor;
	while (tmp1){
		*tmp2 = new t_inv;
		(*tmp2)->materia = tmp1->materia->clone();
		(*tmp2)->is_equiped = tmp1->is_equiped;
		(*tmp2)->next = tmp1->next;
		(*tmp2)->prev = tmp1->prev;
		(*tmp2) = (*tmp2)->next;
		tmp1 = tmp1->next;
	}
}

Character& Character::operator=(const Character &other){
	t_inv	*tmp1;
	t_inv	**tmp2;

	if (this != &other){
		this->_name = other._name;
		this->_size = other._size;
		while (this->_inv){
			tmp1 = this->_inv;
			this->_inv = this->_inv->next;
			delete tmp1;
		}
		while (this->_floor){
			tmp1 = this->_floor;
			this->_floor = this->_inv->next;
			delete tmp1;
		}
		tmp1 = other._inv;
		tmp2 = &this->_inv;
		while (tmp1){
			*tmp2 = new t_inv;
			(*tmp2)->materia = tmp1->materia->clone();
			(*tmp2)->is_equiped = tmp1->is_equiped;
			(*tmp2)->next = tmp1->next;
			(*tmp2)->prev = tmp1->prev;
			(*tmp2) = (*tmp2)->next;
			tmp1 = tmp1->next;
		}
		tmp1 = other._floor;
		tmp2 = &this->_floor;
		while (tmp1){
			*tmp2 = new t_inv;
			(*tmp2)->materia = tmp1->materia->clone();
			(*tmp2)->is_equiped = tmp1->is_equiped;
			(*tmp2)->next = tmp1->next;
			(*tmp2)->prev = tmp1->prev;
			(*tmp2) = (*tmp2)->next;
			tmp1 = tmp1->next;
		}
	}
	return (*this);
}

std::string const & Character::getName() const{return (_name);}

void Character::equip(AMateria* m){

}

void Character::unequip(int idx){
	t_inv	**tmp;
	t_inv	*tmp3;

	if (idx < 0 || idx > 3){
		std::cout << "\033[032mError\033[0m bad idx number" << std::endl;
		return ;
	}
	tmp = &this->_inv;
	while (idx > 0 && *tmp){
		(*tmp) = (*tmp)->next;
		idx--;
	}
	if (*tmp){
		t_inv *tmp2 = this->_floor;
		if (!this->_floor || !this->_floor->next)
			this->_floor = *tmp;
		else {
			while (tmp2 && tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = *tmp;
			tmp2->next->is_equiped = false;
		}
		tmp2 = (*tmp)->next;
		tmp3 = (*tmp)->prev;
		if (tmp2)
			tmp2->next = tmp3;
		if (tmp3)
			tmp3->prev = tmp2;
	}
	else
		std::cout << "No Materia at this slot" << std::endl;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3){
		std::cout << "\033[032mError\033[0m bad idx number" << std::endl;
		return ;
	}
	t_inv	*tmp;
	tmp = this->_inv;
	while (idx > 0 && tmp){
		tmp = tmp->next;
		idx--;
	}
	if (tmp)
		tmp->materia->use(target);
	else
		std::cout << "No Materia at this slot" << std::endl;
}
