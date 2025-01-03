/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:19:57 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 19:27:21 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", RRF_GRADE_SIGNED, RRF_GRADE_EXECUTE), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() <= this->getGradeToExecute())
		_formAction();
	else
	 	throw RobotomyRequestForm::GradeTooLowException();
}

void	RobotomyRequestForm::_formAction() const{
	srand(time(0));
	if ((rand() % 100) >= 50)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomization of " << _target << " failed!" << std::endl;
}
