/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:40:53 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 18:54:43 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/AForm.hpp"
#include "../class/Bureaucrat.hpp"
#include <iostream>
#include <ostream>

AForm::~AForm(){}

AForm::AForm(std::string name, const int gradeToSigned, const int gradeToExecute) :
	_name(name), _signed(false), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute){
	if (gradeToSigned < MAX_LVL || gradeToExecute < MAX_LVL)
		throw AForm::GradeTooHighException();
	if (gradeToSigned > MIN_LVL || gradeToExecute > MIN_LVL)
		throw AForm::GradeTooLowException();
}

int				AForm::getGradeToSigned() const{return (_gradeToSigned);}
int				AForm::getGradeToExecute() const{return (_gradeToExecute);}
std::string		AForm::getName() const{return (_name);}
bool			AForm::getSigned() const{return (_signed);}

void AForm::printForm() const{
	std::cout << std::endl << "╔══════════════════════════════════════╗" << std::endl;
	std::cout << "║  [AForm] \" " << getName() << " \"" << std::endl;
	std::cout << "║" << std::endl;
	if (getSigned())
		std::cout << "║  Signed:         \033[32m[true]\033[0m" << std::endl;
	else
		std::cout << "║  Signed:         \033[31m[false]\033[0m" << std::endl;
	std::cout << "║  gradeToSigned:  [" << getGradeToSigned() << "]" << std::endl;
	std::cout << "║  gradeToExecute: [" << getGradeToExecute() << "]" << std::endl;
	std::cout << "║" << std::endl;
	std::cout << "╚══════════════════════════════════════╝" << std::endl;
}

void	AForm::beSigned(Bureaucrat &other){
	if (other.getGrade() <= this->getGradeToSigned()){
		other.signForm(*this, 1);
		this->_signed = true;
	}
	else
		other.signForm(*this, 0);
}
