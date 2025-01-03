/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:42:29 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 02:30:36 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <exception>
#include "Form.hpp"

# define MAX_LVL 1
# define MIN_LVL 150

class Bureaucrat
{
	private:
		std::string _name;
		int			_grade;
		Bureaucrat();

	public:
		~Bureaucrat();
		Bureaucrat(std::string, int);
		Bureaucrat& operator=(Bureaucrat &other);
		std::string getName() const;
		int 		getGrade() const;
		void		promotion(int = 1);
		void		demotion(int = 1);
		void		signForm(const Form& other, const bool signe) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw(){
				return ("Bureaucrat Grade too high !");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw(){
			return ("Bureaucrat Grade too low !");
		}
	};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other);

#endif
