/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:16:04 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 02:33:02 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try{
		Bureaucrat ilkay("ilkay", 150);
		std::cout << ilkay << std::endl;
		Form form1("manger du chocolat", 100, 30);
		ilkay.promotion(50);
		form1.beSigned(ilkay);
		std::cout << form1 << std::endl;
	}
	catch (const std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}
