/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:51:41 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 19:00:31 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string name = "HI THIS IS BRAIN";
	std::string *stringPTR = &name;
	std::string &stringREF = name;

	std::cout << "memory adress of the string:   " << &name << std::endl;
	std::cout << "memory adress stringPTR held:  " << stringPTR << std::endl;
	std::cout << "memory adress stringREF held:  " << &stringREF << std::endl << std::endl;

	std::cout << "the string:       " << name << std::endl;
	std::cout << "stringPTR value:  " << *stringPTR << std::endl;
	std::cout << "stringREF value:  " << stringREF << std::endl;
}
