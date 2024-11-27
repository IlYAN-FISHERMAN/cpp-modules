/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:59:58 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/26 19:57:31 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	_fixedPoint;
		static const int _frac = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed& operator=(const Fixed &other);
		Fixed(const Fixed &data);

		Fixed(int value);
		Fixed(float value);

		bool operator>(const Fixed &other);
		bool operator>=(const Fixed &other);
		bool operator<(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator==(const Fixed &other);
		bool operator!=(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator/(const Fixed &other);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed& operator--();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
		
		static Fixed& max(Fixed &fixed1, Fixed &fixed2){return ((fixed1._fixedPoint > fixed2._fixedPoint) ? fixed1 : fixed2);};
		static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2){return ((fixed1._fixedPoint > fixed2._fixedPoint) ? fixed1 : fixed2);};
		static Fixed& min(Fixed &fixed1, Fixed &fixed2){return ((fixed1._fixedPoint < fixed2._fixedPoint) ? fixed1 : fixed2);};
		static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2){return ((fixed1._fixedPoint < fixed2._fixedPoint) ? fixed1 : fixed2);};
};

std::ostream& operator<<(std::ostream &os, const Fixed &other);

#endif
