/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:39:28 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/06 17:20:39 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){(void)other;return (*this);}

void	ScalarConverter::convert(const std::string str){
	std::cout << "char: " << static_cast<char>(str[0]) << std::endl;
	std::cout << "int: " << std::stof(str) << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}
