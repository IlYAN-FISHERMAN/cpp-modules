/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:40:53 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/06 12:29:15 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form(){}

Form::Form(std::string name, const int gradeToSigned, const int gradeToExecute) :
	_name(name), _signed(false), _gradeToSigned(gradeToSigned), _gradeToExecute(gradeToExecute){
	if (gradeToSigned < MAX_LVL || gradeToExecute < MAX_LVL)
		throw Form::GradeTooHighException();
	if (gradeToSigned > MIN_LVL || gradeToExecute > MIN_LVL)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form &other){
	if (this != &other)
		;
	return (*this);
}

int				Form::getGradeToSigned() const{return (_gradeToSigned);}
int				Form::getGradeToExecute() const{return (_gradeToExecute);}
std::string		Form::getName() const{return (_name);}
bool			Form::getSigned() const{return (_signed);}

std::ostream& operator<<(std::ostream &fd, const Form &other){
	fd << std::endl << "╔══════════════════════════════════════╗" << std::endl;
	fd << "║  [Form] \" " << other.getName() << " \"" << std::endl;
	fd << "║" << std::endl;
	if (other.getSigned())
		fd << "║  Signed:         \033[32m[true]\033[0m" << std::endl;
	else
		fd << "║  Signed:         \033[31m[false]\033[0m" << std::endl;
	fd << "║  gradeToSigned:  [" << other.getGradeToSigned() << "]" << std::endl;
	fd << "║  gradeToExecute: [" << other.getGradeToExecute() << "]" << std::endl;
	fd << "║" << std::endl;
	fd << "╚══════════════════════════════════════╝" << std::endl;
	return (fd);
}

void	Form::beSigned(Bureaucrat &other){
	if (other.getGrade() <= this->getGradeToSigned()){
		this->_signed = true;
		std::cout << other.getName() << " signed " << getName() << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

void    Form::setSigned(bool sign){_signed = sign;}
