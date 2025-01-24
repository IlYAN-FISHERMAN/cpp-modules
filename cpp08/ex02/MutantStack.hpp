/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:53:11 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/24 14:17:28 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <iterator>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin(){return this->c.begin();}
	iterator end(){return this->c.end();}

	const_iterator begin() const{return this->c.begin();}
	const_iterator end() const{return this->c.end();}
};

#endif
