/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:14:17 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/07 15:09:37 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", SCF_GRADE_SIGNED, SCF_GRADE_EXECUTE), _target(target + "_shrubbery"){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() <= this->getGradeToExecute()){
		_formAction();
		std::cout << getName() << " created a tree?? (really?, go check it)" << std::endl;
	}
	else
	 	throw ShrubberyCreationForm::GradeTooLowException();
}

void	ShrubberyCreationForm::_formAction() const{
	std::ofstream	tree(_target.c_str());

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
