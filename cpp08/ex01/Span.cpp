/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:50:26 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/21 22:09:23 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>

Span::Span(){}

Span::Span(int nb) : _nbr(nb){}

Span::~Span(){}

void Span::addNumber(int nb){
	if (_tab.size() == _nbr)
		throw NoEnoughtSpace();
	_tab.push_back(nb);
}

unsigned int Span::shortestSpan(){

	if (_tab.size() <= 1)
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

	if (_tab.size() <= 1)
		return 0;
	return ((*std::max_element(_tab.begin(), _tab.end())
		 - (*std::min_element(_tab.begin(), _tab.end()))));
}

long	Span::operator[](const size_t it){return (_tab[it]);}
