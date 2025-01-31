/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:08:41 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/31 20:59:00 by ilyanar          ###   LAUSANNE.ch       */
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
		std::cout << "everything good !" << std::endl << "parsing begin:" << std::endl << std::endl;
		btc->compareInput();
		delete btc;
	}
	catch (const std::exception &other){
		std::cout << other.what() << std::endl;
	}
}
