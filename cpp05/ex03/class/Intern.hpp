/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:48:06 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/05 19:21:52 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <string>

# define FORMS_NBR 3

class Formula;

class Intern
{
	private:
		std::string _forms[FORMS_NBR];
		Formula*	_lstForm;
	public:
		enum{
			PPF,
			RRF,
			SCF
		};
		Intern();
		~Intern();
		AForm* makeForm(std::string name, std::string target);
		AForm* creatSCF(std::string);
		AForm* creatPPF(std::string);
		AForm* creatRRF(std::string);

		class NoFormsException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return ("No forms founded !");
			}
		};
};

class Formula
{
	private:
		AForm* (Intern::*_functionExec)(std::string);
		Formula* _next;
	public:
		Formula(AForm* (Intern::*)(std::string));
		AForm* (Intern::*getFormula())(std::string);
		~Formula();
		Formula* 	getNext();
		void		setNext(Formula*);
};

#endif
