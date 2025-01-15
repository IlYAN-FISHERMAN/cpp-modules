/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:39:28 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/09 14:18:56 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <string>
#include <stdlib.h>

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){(void)other;return (*this);}

void	ScalarConverter::convert(const std::string str){
	double nb = 0;
	char *tmp = NULL;

	if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]))
		nb = static_cast<double>(str[0]);
	else
		nb = strtod(str.c_str(), &tmp);
	std::cout << tmp << std::endl;
	if (tmp && strlen(tmp) > 1){
		std::cerr << "\033[31mBad string format\033[0m" << std::endl;
		return ;
	}
	if (str.length() > 6)
		std::cout << std::setprecision(str.length());
	std::cout << "char:\t";
	if (nb >= 0 && nb <= 128 && !isprint(static_cast<char>(nb)))
		std::cout << "Non displayable" << std::endl;
	else if (nb > 128 || nb < 0)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
	std::cout << "int:\t";
	if (nb < INT_MAX && nb > INT_MIN)
		std::cout << static_cast<int>(nb) << std::endl;
	else
		std::cout << "Impossible" << std::endl;
	std::cout << "float:\t" << static_cast<float>(nb);
	if (trunc(nb) == nb && static_cast<float>(nb) != INFINITY)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double:\t" << nb;
	if (trunc(nb) == nb && nb != INFINITY)
		std::cout << ".0";
	std::cout << std::endl;
}
