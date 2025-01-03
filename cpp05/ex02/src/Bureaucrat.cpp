/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:46:54 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 19:35:35 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Random Bureaucrat"), _grade(0){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) :_name(name){
	if (grade < MAX_LVL)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_LVL)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other){
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return os;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &other){
	if (this != &other){
		_name = other._name;
		_grade = other._grade;
	}
	return(*this);
}

std::string	Bureaucrat::getName() const{return (_name);}

int			Bureaucrat::getGrade() const{return (_grade);}

void		Bureaucrat::promotion(int grade){
	if (_grade - grade < MAX_LVL)
		throw Bureaucrat::GradeTooHighException();
	_grade -= grade;
	std::cout << _name << " got a promotion to the grade " << _grade << " !" << std::endl;
}

void		Bureaucrat::demotion(int grade){
		if (_grade + grade > MIN_LVL)
		throw Bureaucrat::GradeTooLowException();
	_grade += grade;
	std::cout << _name << " got a demotion to the grade " << _grade << " !" << std::endl;
}

void		Bureaucrat::signForm(const AForm& other, const bool signe) const{
	if (signe)
		std::cout << getName() << " signed " << other.getName() << std::endl;
	else
		std::cout << getName() << " couldn’t sign " << other.getName()
			<< " because " << Bureaucrat::GradeTooLowException().what() << std::endl;
}

void		Bureaucrat::executeForm(AForm const & form){
	if (getGrade() <= form.getGradeToExecute()){
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}
