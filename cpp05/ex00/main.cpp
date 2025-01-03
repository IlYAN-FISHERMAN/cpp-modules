/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:16:04 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/30 14:45:21 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try{
		Bureaucrat ilkay("ilkay", 2);
		std::cout << ilkay << std::endl;
		ilkay.promotion();
		ilkay.demotion(100);
		Bureaucrat tmp("maria", 150);
		std::cout << tmp << std::endl;
		tmp.promotion();
		tmp.promotion(148);
		std::cout << tmp << std::endl;
		tmp.promotion();
	}
	catch (const std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}
