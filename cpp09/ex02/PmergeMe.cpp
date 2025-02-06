/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:07:58 by ilyanar           #+#    #+#             */
/*   Updated: 2025/02/05 17:53:01 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

VectSort::VectSort(std::string){
}

VectSort::~VectSort(){}

VectSort::VectSort(const VectSort &other) : _data(other._data){}

VectSort& VectSort::operator=(const VectSort &other){
	if (this != &other){
		_data = other._data;
	}
	return *this;
}

void VectSort::sort(){

}


ListSort::ListSort(std::string){
	
}
ListSort::~ListSort(){}

ListSort::ListSort(const ListSort &other) : _data(other._data){}

ListSort& ListSort::operator=(const ListSort &other){
	if (this != &other){
		_data = other._data;
	}
	return *this;
}

void ListSort::sort(){}
