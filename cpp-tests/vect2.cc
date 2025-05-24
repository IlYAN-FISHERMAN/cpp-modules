/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:10:59 by ilyanar           #+#    #+#             */
/*   Updated: 2025/05/24 17:25:15 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hh"
#include <string>

vect2::vect2() : _x(0), _y(0){}

vect2::vect2(int x, int y) : _x(x), _y(y){}

vect2::~vect2(){}

vect2::vect2(const vect2 &other) : _x(other._x), _y(other._y){}

vect2& vect2::operator=(const vect2 &other){
	if (this != &other){
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}

vect2	vect2::operator*(int nb) const{
	return (vect2(_x * nb, _y *nb));
}

vect2	vect2::operator*(const vect2 &v) const{
	return (vect2(_x * v._x, _y * v._y));
}

vect2	vect2::operator+(int nb) const{
	return (vect2(_x + nb, _y +nb));
}

vect2	vect2::operator+(const vect2 &v) const{
	return (vect2(_x + v._x, _y + v._y));
}

std::ostream& operator<<(std::ostream& os, const vect2 &other){
	os << "v: {" << other[0] << " ," << other[1] << "}";
	return (os);
}

int&  vect2::operator[](int nb){
	if (nb == 0)
		return _x;
	return _y;
}

int  vect2::operator[](int nb) const{
	if (nb == 0)
		return _x;
	return _y;
}

int main(){
	std::string tmp("lol ptdr");
	tmp.substr().find("l");
	vect2 v1(1 , 2);
	const vect2 v3(10, 4);

	v1 = v1 + v3 * 2;
	std::cout << v1 << std::endl;
}
