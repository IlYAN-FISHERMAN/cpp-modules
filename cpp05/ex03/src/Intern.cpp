/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:50:42 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/05 19:44:58 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Intern.hpp"
#include <exception>

AForm* Intern::creatSCF(std::string target){return (new ShrubberyCreationForm(target));}

AForm* Intern::creatPPF(std::string target){return (new PresidentialPardonForm(target));}

AForm* Intern::creatRRF(std::string target){return (new RobotomyRequestForm(target));}

AForm* (Intern::*Formula::getFormula())(std::string){return (this->_functionExec);}

Formula* Formula::getNext(){return (_next);}

void	Formula::setNext(Formula* next){_next = next;}


Formula::Formula(AForm* (Intern::*funct)(std::string)) : _functionExec(funct){}

Formula::~Formula(){}


Intern::Intern() : _lstForm(nullptr){
	Formula *tmp;
	_forms[PPF] = "presidential pardon";
	_forms[RRF] = "robotomy request";
	_forms[SCF] = "shrubbery creation";
	for (int i = 0; i < FORMS_NBR; i++){
		Formula* newFormula = NULL;
		switch (i){
			case (PPF):
				newFormula = new Formula(&Intern::creatPPF);
				break;
			case (RRF):
				newFormula = new Formula(&Intern::creatRRF);
				break;
			case (SCF):
				newFormula = new Formula(&Intern::creatSCF);
				break;
			default:
				break;
		}
		if (!_lstForm)
			_lstForm = newFormula;
		else
			tmp->setNext(newFormula);
		tmp = newFormula;
	}
}

Intern::~Intern(){
	Formula *tmp = _lstForm;
	
	while (tmp){
		_lstForm = _lstForm->getNext();
		delete tmp;
		tmp = _lstForm;
	}
}

AForm* Intern::makeForm(std::string name, std::string target){
	Formula* tmp = this->_lstForm;

	for (int i = 0; i <= FORMS_NBR + 1; i++){
		if (i >= FORMS_NBR)
			throw NoFormsException();
		else if (_forms[i] == name){
			while (i > 0){
					i--;
					tmp = tmp->getNext();
				}
			AForm* (Intern::*functionExec)(std::string) = tmp->getFormula();
			return ((*this.*functionExec)(target));
		}
	}
	return (NULL);
}
