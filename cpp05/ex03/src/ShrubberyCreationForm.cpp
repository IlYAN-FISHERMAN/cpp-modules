/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:14:17 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 19:14:44 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", SCF_GRADE_SIGNED, SCF_GRADE_EXECUTE), _target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() <= this->getGradeToExecute())
		_formAction();
	else
	 	throw ShrubberyCreationForm::GradeTooLowException();
}

void	ShrubberyCreationForm::_formAction() const{
	std::ofstream	tree(_target + "_shrubbery");

	tree <<	"				  # #### ####" << std::endl;
	tree << "				### \\/#|### |/####" << std::endl;
	tree << "			   ##\\/#/ \\||/##/_/##/_#" << std::endl;
	tree << "			 ###  \\/###|/ \\/ # ###" << std::endl;
	tree << "		   ##_\\_#\\_\\## | #/###_/_####" << std::endl;
	tree << "		  ## #### # \\ #| /  #### ##/##" << std::endl;
	tree << "		   __#_--###`  |{,###---###-~" << std::endl;
	tree << "					 \\ }{" << std::endl;
	tree << "						  }}{" << std::endl;
	tree << "					  }}{" << std::endl;
	tree << "					  {{}" << std::endl;
	tree << "					, -=-~{ .-^- _" << std::endl;
}
