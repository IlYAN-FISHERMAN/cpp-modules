/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:08:41 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/27 17:40:15 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

std::string DateTime(time_t time, const char* format)
{
    char buffer[90];
    struct tm* timeinfo = localtime(&time);
    strftime(buffer, sizeof(buffer), format, timeinfo);
    return buffer;
}

int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Usage: ./btc <input.txt>" << std::endl;
		return (-1);
	}
	std::ifstream inputFile(av[1]);
	std::ifstream dataFile("./data.csv");
	if (!inputFile.is_open() || !dataFile.is_open()){
		std::cout << "File"  "can\'t be open" << std::endl;
		return (-1);
	}
	std::string input;
	getline(inputFile, input);
	std::cout << input << std::endl;
	// struct tm	tm;
	// explicit_bzero(&tm, sizeof(tm));
	// strptime("2025-01-21w", "%Y-%m-%d", &tm);
	// std::cout << DateTime(mktime(&tm), "%Y-%m-%d") << std::endl;
}
