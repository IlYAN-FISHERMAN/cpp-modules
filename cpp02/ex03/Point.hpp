/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:11:08 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/27 00:48:53 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <cmath>
#include <cstdlib>

# ifndef FUNCT
#  define FUNCT 0
# endif

class Point
{
	private:
		Fixed	const _x;
		Fixed	const _y;
	public:
		Point();
		~Point();
		Point(const Point &other);
		Point(const float x, const float y);
		Point& operator=(const Point &other);
		float	getX() const;
		float	getY() const;
		float area(Point const &a, Point const &b, Point const &c) const;
		bool barycentic(Point const a, Point const b, Point const c, Point const point) const;
		bool cramersRule(Point const a, Point const b, Point const c, Point const point) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
