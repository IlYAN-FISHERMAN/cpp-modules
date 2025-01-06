/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:16:04 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/06 12:31:33 by ilyanar          ###   LAUSANNE.ch       */
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
		Form form2("Correction", 2, 2);
		ilkay.promotion(99);
		ilkay.signForm(form2);
		std::cout << form1 << std::endl;
	}
	catch (const std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}
