/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:55:59 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/14 21:06:58 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T>void iter(T *array, T len, void (*func)(T*)){
	for (T i = 0; i < (int)len; i++){
		(*func)(&array[(int)i]);
	}
}

template <class T>void	half_half(T *nb){
	std::cout << ((*nb <= 50) ? "less/equal than 50" : "more than 50") << std::endl;
}

template <class T> void display(T *nb){
	std::cout << "nb: " << *nb << "\t";
	half_half(nb);
}

template <class T> void	divise(T *nb){
	*nb /= 2;
	std::cout << "nb after division: " << *nb << std::endl;
}

template <class T> T max(T x, T y){
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
