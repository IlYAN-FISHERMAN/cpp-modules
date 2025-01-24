/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:50:26 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/24 14:47:04 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <vector>

Span::Span(){}

Span::Span(int nb) : _it(0), _tab(nb), _len(nb){}

Span::~Span(){}

void Span::addNumber(int nb){
	if (_it == _len)
		throw NoEnoughtSpace();
	_tab.at(_it) = nb;
	_it++;
}

unsigned int Span::shortestSpan(){

	if (_it <= 1)
		return 0;
	unsigned int	span = UINT_MAX;

	std::vector<int> tmp(_tab);
	std::sort(tmp.begin(), tmp.end());
	for (int i = 0; &tmp[i] < &tmp.back(); ++i)
		if (span > labs(tmp[i + 1]) - labs(tmp[i]))
			span = labs(tmp[i + 1]) - labs(tmp[i]);

	return span;
}

unsigned int Span::longestSpan(){

	if (_it <= 1)
		return 0;
	return ((*std::max_element(_tab.begin(), _tab.end())
		 - (*std::min_element(_tab.begin(), _tab.end()))));
}

int&	Span::operator[](const size_t it){return (_tab[it]);}

std::vector<int>& Span::getTab(){return (_tab);}

int	Span::fillNumber(std::vector<int>::iterator	begin, std::vector<int>::iterator end){
	srand(time(0));
	for (;begin != end; begin++, _it++)
		*begin = rand() % 100+1;
	return (0);
}
