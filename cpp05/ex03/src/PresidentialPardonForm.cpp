/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:29:00 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 19:31:27 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", PPF_GRADE_SIGNED, PPF_GRADE_EXECUTE), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() <= this->getGradeToExecute())
		_formAction();
	else
	 	throw PresidentialPardonForm::GradeTooLowException();
}

void	PresidentialPardonForm::_formAction() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
