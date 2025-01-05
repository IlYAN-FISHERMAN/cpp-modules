/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:16:04 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/05 20:38:56 by ilyanar          ###   LAUSANNE.ch       */
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
		Bureaucrat master("ilkay", 1);
		Bureaucrat begginner("fabien", 50);
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm *lolilol = someRandomIntern.makeForm("shrubbery creation", "fabien");

		lolilol->beSigned(begginner);
		begginner.executeForm(*lolilol);
		rrf->execute(Bureaucrat("ilkay", 1));
		// master.signForm(*rrf);
		rrf->beSigned(master);
		master.demotion(100);
		rrf->printForm();
		lolilol->printForm();
		delete rrf;
		delete lolilol;
	}
	catch (const std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}
