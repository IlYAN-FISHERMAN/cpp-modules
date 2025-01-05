/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:16:04 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/05 19:47:12 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "class/AForm.hpp"
#include "class/Intern.hpp"
#include "class/Bureaucrat.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include "class/RobotomyRequestForm.hpp"
#include "class/PresidentialPardonForm.hpp"

int main(void)
{
	try{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf->execute(Bureaucrat("ilkay", 1));
		delete rrf;
	}
	catch (const std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}
