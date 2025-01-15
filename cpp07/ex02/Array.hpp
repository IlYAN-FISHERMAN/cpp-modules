/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:09:22 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/15 11:40:15 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template <class T> class Array
{
	private:
		T		*_array;
		size_t	_len;
	public:
		Array() : _array(new T[0]()), _len(0){
	}

		~Array(){
			delete [] _array;
	}

		Array(const Array &other) : _len(other._len){
			if (this != &other){
				this->_array = new T[_len]();
				for (size_t i = 0; i < _len; i++)
					this->_array[i] = other._array[i];
			}
		}

		T& operator[](size_t n){
		if (n >= _len)
			throw BadIndexException();
		return (_array[n]);
	}

		class BadIndexException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
				return ("Bad Index exception!");
			}
		};

		Array& operator=(const Array &other){
			if (this != &other){
				std::cout << "copy operator called" << std::endl;
				this->_len = other._len;
				delete [] this->_array;
				this->_array = new T[_len]();
				for (size_t i = 0; i < _len; i++)
					this->_array[i] = other._array[i];
			}
		return (*this);
	}

		Array(size_t n) : _array(new T[n]()), _len(n){
		for (size_t i = 0; i < n; i++)
			_array[i] = 0;
	}

		T	size(){return (_len);};
};

#endif
