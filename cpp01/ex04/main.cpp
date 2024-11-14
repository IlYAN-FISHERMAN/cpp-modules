/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:13:19 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/14 01:18:53 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void	replace_lines(std::ifstream &file, std::string &old, std::string &New)
{
	std::string gline;
	std::ofstream MyFile("file.replace");

	while (std::getline(file, gline))
		MyFile << gline << std::endl;
	(void)old;
	(void)New;
}

int	main(int ac, char **av)
{
	std::string str[3];

	if (ac != 4){
		std::cerr << "Bad number of arg." << std::endl;
		std::cerr << "Usage: ./reverse <file> <str1> <str2>" << std::endl;
		return (1);
	}
	str[0] = av[1];
	str[1] = av[2];
	str[2] = av[3];
	if (str[0] == "" || str[1] == "" || str[2] == "")
		std::cout << "Empty string" << std::endl;

	std::ifstream file(str[0], std::ifstream::in);
	if (!file.is_open()){
		std::cerr << "Error file" << std::endl;
		return (1);
	}
	replace_lines(file, str[1], str[2]);
	file.close();
}
