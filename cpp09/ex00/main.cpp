/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:08:41 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/28 09:34:59 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <_stdio.h>
#include <fstream>

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
	try{
		Btc btc(av[1], "./data.csv");
		std::string input;
		getline(btc.getInput(), input);
		for (;btc.getInput().eof(); getline(btc.getInput(), input))
			std::cout << input << std::endl;
	}
	catch (const std::exception &other){
		std::cout << other.what() << std::endl;
	}
	// struct tm	tm;
	// explicit_bzero(&tm, sizeof(tm));
	// strptime("2025-01-21w", "%Y-%m-%d", &tm);
	// std::cout << DateTime(mktime(&tm), "%Y-%m-%d") << std::endl;
}
