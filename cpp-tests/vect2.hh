/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:11:27 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/23 16:28:11 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

#include <ostream>
#include <iostream>
class vect2
{
	private:
		int _x;
		int _y;
	public:
		vect2();
		vect2(int, int);
		~vect2();
		vect2(const vect2 &other);
		vect2& operator=(const vect2 &other);

		vect2 operator*(int) const;
		vect2 operator*(const vect2 &other) const;
		vect2 operator+(int) const;
		vect2 operator+(const vect2 &other) const;
		int&  operator[](int);
		int  operator[](int) const;
};

std::ostream& operator<<(std::ostream& os, const vect2 &other);

#endif
