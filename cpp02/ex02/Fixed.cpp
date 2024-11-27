/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:01:04 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/26 23:19:07 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedPoint(0){
	/*std::cout << "Default constructor called" << std::endl;*/
}

Fixed::~Fixed(){
	/*std::cout << "Destructor called" << std::endl;*/
}

Fixed::Fixed(const Fixed &data) : _fixedPoint(data.getRawBits()){
	/*std::cout << "Copy constructor called" << std::endl;*/
}

Fixed::Fixed(int value) : _fixedPoint(value * (1 << _frac)){
	/*std::cout << "Int constructor called" << std::endl;*/
}

Fixed::Fixed(float value) : _fixedPoint(value * (1 << _frac)){
	/*std::cout << "Float constructor called" << std::endl;*/
}

Fixed& Fixed::operator=(const Fixed &other){
	/*std::cout << "Copy assignment operator called" << std::endl;*/
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}


bool Fixed::operator>(const Fixed &other){return ((_fixedPoint > other._fixedPoint) ? 1 : 0);}

bool Fixed::operator>=(const Fixed &other){return ((_fixedPoint >= other._fixedPoint) ? 1 : 0);}

bool Fixed::operator<(const Fixed &other){return ((_fixedPoint < other._fixedPoint) ? 1 : 0);}

bool Fixed::operator<=(const Fixed &other){return ((_fixedPoint <= other._fixedPoint) ? 1 : 0);}

bool Fixed::operator==(const Fixed &other){return ((_fixedPoint == other._fixedPoint) ? 1 : 0);}

bool Fixed::operator!=(const Fixed &other){return ((_fixedPoint != other._fixedPoint) ? 1 : 0);}


Fixed Fixed::operator*(const Fixed &other){
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator+(const Fixed &other){
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other){
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other){
	if (other._fixedPoint == 0){
		std::cerr << "Division by 0 is undefined" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}


Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	++_fixedPoint;
	return (tmp);
}

Fixed& Fixed::operator++(){
	++_fixedPoint;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	--_fixedPoint;
	return (tmp);
}

Fixed& Fixed::operator--(){
	--_fixedPoint;
	return (*this);
}


std::ostream& operator<<(std::ostream& os ,const Fixed &other)
{
        os << other.toFloat();
        return (os);
}


float Fixed::toFloat( void ) const{ return((float)_fixedPoint / (1 << _frac));}

int Fixed::toInt( void ) const{ return(_fixedPoint / (1 << _frac));}

int Fixed::getRawBits(void) const{
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw){
	_fixedPoint = raw;
}

