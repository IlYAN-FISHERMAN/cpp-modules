/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:59:58 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/22 15:17:41 by ilyanar          ###   LAUSANNE.ch       */
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
		Fixed(const Fixed &data);
		Fixed(int value);
		Fixed(float value);
		Fixed& operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

	std::ostream& operator<<(std::ostream &os, const Fixed &other);
#endif
