/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:57:44 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/21 18:54:09 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <class T>int	easyfind(T &content, int nb){

	typename T::iterator tmp = std::find(content.begin(), content.end(), nb);
	if (tmp == content.end())
		throw ("No number found");
	return (nb);
}

template <class T>
int	easyfind(const T &content, const int nb){

	typename T::iterator tmp = std::find(content.begin(), content.end(), nb);
	if (tmp == content.end())
		throw ("No number found");
	return (nb);
}

#endif
