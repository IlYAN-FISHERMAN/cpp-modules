/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:16:04 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 20:44:51 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "class/AForm.hpp"
#include "class/Bureaucrat.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include "class/RobotomyRequestForm.hpp"
#include "class/PresidentialPardonForm.hpp"

int main(void)
{
	try{
		Bureaucrat ilkay("ilkay", 1);
		ShrubberyCreationForm 	tree1("myroom");
		PresidentialPardonForm	presidente("macron");
		RobotomyRequestForm		robot("fabien");

		ilkay.executeForm(robot);
		ilkay.executeForm(presidente);
		ilkay.executeForm(tree1);
		tree1.beSigned(ilkay);
		presidente.beSigned(ilkay);
		robot.beSigned(ilkay);
		presidente.printForm();
		tree1.printForm();
		robot.printForm();

		std::cout << ilkay << std::endl;
	}
	catch (const std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}
