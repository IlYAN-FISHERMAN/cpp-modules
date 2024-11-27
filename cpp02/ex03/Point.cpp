/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:11:31 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/27 00:36:10 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(){}

Point::~Point(){}

Point::Point(const Point &other) : _x(other._x), _y(other._y){}

Point::Point(const float x, const float y): _x(x), _y(y){}

Point& Point::operator=(const Point &other){
	(void)other;
	return *this;
}

float	Point::getX() const{
	return (_x.toFloat());
}

float	Point::getY() const{
		return (_y.toFloat());
}
