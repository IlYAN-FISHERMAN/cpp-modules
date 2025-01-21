/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:22:37 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/21 22:09:21 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		size_t				_nbr;
		std::vector<int>	_tab;
		Span();
	public:
		Span(int nb);
		Span(const Span &other);
		~Span();
		Span& operator=(const Span &other);

		void addNumber(int);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		long operator[](const size_t it);

	class NoEnoughtSpace : public std::exception
	{
		public:
		const char * what() const throw(){
			return ("Already have this number in the list");
		}
	};
};

#endif
