/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:01:04 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/24 16:55:07 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &data) : _fixedPoint(data.getRawBits()){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int value) : _fixedPoint(value * (1 << _frac)){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value) : _fixedPoint(value * (1 << _frac)){
		std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os ,const Fixed &other)
{
	os << other.toFloat();
	return (os);
}

int Fixed::getRawBits(void) const{
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw){
	_fixedPoint = raw;
}

float Fixed::toFloat( void ) const{ return((float)_fixedPoint / (1 << _frac));}

int Fixed::toInt( void ) const{ return(_fixedPoint / (1 << _frac));}
