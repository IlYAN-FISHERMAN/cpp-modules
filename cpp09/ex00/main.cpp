/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:08:41 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/30 02:45:53 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

bool is_data_value(const char *input){
	std::stringstream stream(input);
	std::string date;
	std::string separator;
	std::string value;
	std::string end;

	stream >> date >> separator >> value >> end;
	if (date == "date" && separator == "|" && value == "value" && end.empty())
		return true;
	return false;
}

int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Usage: ./btc <input.txt>" << std::endl;
		return (-1);
	}
	try{
		Btc *btc = new Btc(av[1], "./data.csv");
		// btc.parseInput();
		delete btc;
	}
	catch (const std::exception &other){
		std::cout << other.what() << std::endl;
	}
	// struct tm	tm;
	// explicit_bzero(&tm, sizeof(tm));
	// strptime("2025-01-21w", "%Y-%m-%d", &tm);
	// std::cout << DateTime(mktime(&tm), "%Y-%m-%d") << std::endl;
}
