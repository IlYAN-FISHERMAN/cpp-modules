/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:55:42 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/14 14:39:57 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T> T max(T x, T y){
	if (x == y)
		return (y);
	return ((x < y) ? y : x);
}

template <typename T> T min(T x, T y){
	if (x == y)
		return (y);
	return ((x < y) ? x : y);
}

template <typename T>void swap(T &x, T &y){
	T tmp = x;
	x = y;
	y = tmp;
}

#endif
