/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:19:41 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/27 02:35:12 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float Point::area(Point const &a, Point const &b, Point const &c) const
{
	return (std::abs(a._x.toFloat() * (b._y.toFloat() - c._y.toFloat())
		 + b._x.toFloat() * (c._y.toFloat() - a._y.toFloat())
		 + c._x.toFloat() * (a._y.toFloat() - b._y.toFloat())) * 0.5f);
}

bool Point::cramersRule(Point const a, Point const b, Point const c, Point const point) const
{
	float ABC = this->area(a, b, c);
	float PBC = this->area(point, b, c);
	float PAC = this->area(point, a, c);
	float PAB = this->area(point, a, b);

	return (ABC == PBC + PAC + PAB);
}

bool Point::barycentic(Point const a, Point const b, Point const c, Point const point) const
{
	double denominator = std::abs((b.getY() - c.getY()) * (a.getX() - c.getX()) + 
                          (c.getX() - b.getX()) * (a.getY() - c.getY()));
	double A = std::abs((b.getY() - c.getY()) * (point.getX() - c.getX()) + 
                (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
    double B = std::abs((c.getY() - a.getY()) * (point.getX() - c.getX()) + 
                (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
    double C = 1 - A - B;

	return ((A >= 0 && B >= 0 && C >= 0) ? true : false);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	if (FUNCT == 1)
		return (point.barycentic(a, b, c, point));
	return (point.cramersRule(a, b, c, point));
	
}
