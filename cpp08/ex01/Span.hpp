/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:22:37 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/23 00:17:47 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		size_t				_it;
		std::vector<int>	_tab;
		size_t				_len;
		Span();
	public:
		Span(int nb);
		Span(const Span &other);
		~Span();
		Span& operator=(const Span &other);

		void addNumber(int);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		std::vector<int>& getTab();
		int& operator[](const size_t it);
		int	fillNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	class NoEnoughtSpace : public std::exception
	{
		public:
		const char * what() const throw(){
			return ("No enought space");
		}
	};
};

#endif
