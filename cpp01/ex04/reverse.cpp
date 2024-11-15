/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:13:19 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/15 13:07:10 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void	replace_lines(std::ifstream &file, std::string &old, std::string &New, std::string &filename)
{
	std::string		gline;
	size_t			pos;

	std::ofstream	MyFile(filename + ".replace");
	while (std::getline(file, gline))
	{
		pos = 0;
		while (gline.find(old, pos) != gline.npos)
		{
			pos = gline.find(old, pos);
			if (pos > gline.length())
				break ;
			gline.erase(pos, old.length());
			gline.insert(pos, New);
			pos += New.length();
		}
		MyFile << gline << std::endl;
	}
	MyFile.close();
}

int	main(int ac, char **av)
{
	std::string str[3];

	if (ac != 4){
		std::cerr << "Bad number of arg" << std::endl << std::endl;
		std::cerr << "    Usage: ./reverse <file> <str1> <str2>" << std::endl;
		return (1);
	}
	str[0] = av[1];
	str[1] = av[2];
	str[2] = av[3];
	if (str[0].empty()|| str[1].empty()|| str[2].empty())
	{
		std::cout << "Empty string" << std::endl;
		return (1);
	}
	std::ifstream file(str[0], std::ifstream::in);
	if (!file.is_open()){
		std::cerr << "Error file" << std::endl;
		return (1);
	}
	replace_lines(file, str[1], str[2], str[0]);
	file.close();
}
