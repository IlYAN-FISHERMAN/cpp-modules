/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:07:58 by ilyanar           #+#    #+#             */
/*   Updated: 2025/03/11 18:39:48 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

VectSort::VectSort(char *av){

	std::stringstream	stream(av);
	std::string			tmp;
	char *delem;
	long int nbr;

	while (stream >> tmp){
		nbr = std::strtol(tmp.c_str(), &delem, 10);
		if (*delem)
			throw std::runtime_error("Bad number input: " + tmp);
		if (nbr < 0 || nbr > INT_MAX)
			throw std::runtime_error("Bad range number: " + tmp);
		_data.push_back(nbr);
	}
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
