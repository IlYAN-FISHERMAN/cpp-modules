/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:15:21 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/13 19:40:07 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Character.hpp"

int     ft_lstsize(t_flor *lst)
{
        int     i;
        t_flor  *tmp;

    	 i = 1;
        if (!lst)
                return (0);
        tmp = lst->next;
        while (tmp)
        {
                i++;
                tmp = tmp->next;
        }
        return (i);
}

static t_flor  *ft_lstlast(t_flor *lst)
{
        t_flor  *tmp;

        if (!lst)
                return (NULL);
        tmp = lst;
        while (tmp)
        {
                if (tmp->next == NULL)
                        return (tmp);
                else
                        tmp = tmp->next;
        }
        return (tmp);
}

static void    ft_lstadd_back(t_flor **lst, t_flor *neww)
{
        if (!lst || !neww)
                return ;
        if (!*lst)
                *lst = neww;
        else
                ft_lstlast(*lst)->next = neww;
}

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
	
	t_flor	*tmp;

	tmp = _floor;
	while (tmp && _floor){
		tmp = _floor;
		_floor = _floor->next;
		delete tmp;
	}
}

Character::Character(std::string const & name) : _name(name), _floor(NULL), _size(0){
	std::cout << "Character string constructor called" << std::endl;
	for (int i = 0; i < MAX_INV; i++){
		_inv[i].materia = NULL;
		_inv[i].is_equiped = false;
	}
}

Character::Character(Character const & src) : _name(src._name), _floor(NULL), _size(src._size){
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < MAX_INV; i++){
		_inv[i].materia = src._inv[i].materia->clone();
		_inv[i].is_equiped = src._inv[i].is_equiped;
	}
	for (t_flor *tmp = src._floor; tmp; tmp = tmp->next){
		ft_lstadd_back(&_floor, new t_flor);
		ft_lstlast(_floor)->materia = tmp->materia->clone();
		ft_lstlast(_floor)->is_equiped = tmp->is_equiped;
	}
}

Character& Character::operator=(const Character &other){
	std::cout << "Character overload= operator called" << std::endl;
	if (this != &other){
		this->_name = other._name;
		this->_size = other._size;
		for (int i = 0; i < MAX_INV; i++){
			_inv[i].materia = other._inv[i].materia->clone();
			_inv[i].is_equiped = other._inv[i].is_equiped;
		}
		for (t_flor *tmp = other._floor; tmp; tmp = tmp->next){
			ft_lstadd_back(&_floor, new t_flor);
			ft_lstlast(_floor)->materia = tmp->materia->clone();
			ft_lstlast(_floor)->is_equiped = tmp->is_equiped;
		}
	}
	return (*this);
}

std::string const & Character::getName() const{return (_name);}

void Character::equip(AMateria* m){
	for (int i = 0; i < MAX_INV + 1; i++){
		if (i == MAX_INV){
			std::cout << "The inventory is full" << std::endl;
			return ;
		}
		else if (!_inv[i].is_equiped && !_inv[i].materia){
			_inv[i].materia = m;
			_inv[i].is_equiped = true;
			std::cout << _name << " equip " << _inv[i].materia->getType() << std::endl;
			break ;
		}
	}
}

void Character::unequip(int idx){

	if (idx < 0 || idx > 3){
		std::cout << "\033[031m[Error]\033[0m bad idx number" << std::endl;
		return ;
	}
	else if (!_inv[idx].is_equiped || !_inv[idx].materia)
		std::cout << "\033[031m[Error]\033[0m no materia at this idx" << std::endl;
	else{
		std::cout << _name << " unequip " << _inv[idx].materia->getType() << std::endl;
		t_flor	*tmp = new t_flor;
		tmp->next = NULL;
		tmp->materia = NULL;
		tmp->is_equiped = false;
		tmp->materia = _inv[idx].materia;
		_inv[idx].materia = NULL;
		_inv[idx].is_equiped = false;
		tmp->is_equiped = false;
		ft_lstadd_back(&_floor, tmp);
		while(idx < MAX_INV){
			if (idx < 4){
				_inv[idx].materia = _inv[idx + 1].materia;
				_inv[idx].is_equiped = _inv[idx + 1].is_equiped;
				_inv[idx + 1].is_equiped = false;
				_inv[idx + 1].materia = NULL;;
			}
			else{
				_inv[idx].materia = NULL;
				_inv[idx].is_equiped = false;
			}
			idx++;
		}
	}
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3){
		std::cout << "\033[031m[Error]\033[0m bad idx number" << std::endl;
		return ;
	}
	else if (!_inv[idx].is_equiped || !_inv[idx].materia)
		std::cout << "\033[031m[Error]\033[0m no materia at this idx" << std::endl;
	else
		_inv[idx].materia->use(target);
}

void Character::display_floor(){
	t_flor	*tmp;

	tmp = _floor;
	std::cout << "-- FLOOR --" << std::endl << std::endl;
	if (!tmp)
		std::cout << "* floor is empty !*" << std::endl;
	while (tmp){
		std::cout << "╔════════════════════════════════╗" << std::endl;
		std::cout << "║ Materia     : " << tmp->materia->getType() << std::endl;
		std::cout << "║ Is_equiped  : " << tmp->is_equiped << std::endl;
		std::cout << "║ Next        : " << tmp->next << std::endl;
		std::cout << "╚════════════════════════════════╝" << std::endl << std::endl;
		tmp = tmp->next;
	}
}

void Character::display_inv(){
	std::cout << "-- INVENTORY --" << std::endl << std::endl;
	for (int i = 0; i < MAX_INV; i++){
		std::cout << "╔══════════════════════════╗" << std::endl;
		if (_inv[i].is_equiped)
			std::cout << "║ Materia    : " << _inv[i].materia->getType() << std::endl;
		else
			std::cout << "║ Materia    :  empty" << std::endl;
		std::cout << "║ Is_equiped    : " << _inv[i].is_equiped << std::endl;
		std::cout << "╚══════════════════════════╝" << std::endl << std::endl;
	}
}
