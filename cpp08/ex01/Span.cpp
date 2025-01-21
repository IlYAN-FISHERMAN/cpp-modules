/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:50:26 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/21 21:07:28 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>

Span::Span(){}

Span::Span(int nb) : _nbr(nb){}

Span::~Span(){}

void Span::addNumber(int nb){
	if (_tab.size() == _nbr)
		throw NoEnoughtSpace();
	_tab.push_back(nb);
}

long Span::shortestSpan(){

	long span = LONG_MAX;

	std::vector<int> tmp(_tab);
	std::sort(tmp.begin(), tmp.end());
	if (_tab.size() <= 1)
		return span;
	for (size_t i = 0; i < tmp.size() - 1; i++){
		if ((tmp[i+1] - tmp[i]) < span)
			span = tmp[i+1] - tmp[i];
	}
	return ((span < 0) ? span*-1 : span);
}

long Span::longestSpan(){

	std::vector<int> tmp(_tab);
	std::sort(tmp.begin(), tmp.end());
	if (tmp[0] < 0)
		return (tmp[0] + *(tmp.end()-1));
	return (*(tmp.end()-1) - *tmp.begin());
}
