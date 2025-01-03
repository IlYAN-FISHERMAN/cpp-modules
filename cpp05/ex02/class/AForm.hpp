/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:35:24 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 02:46:08 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <ostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string 	_name;
		bool 				_signed;
		const int 			_gradeToSigned;
		const int			_gradeToExecute;
		AForm();
	public:
		virtual ~AForm();
		AForm(std::string, int, int);
		AForm& operator=(const AForm &other);

		virtual int				getGradeToSigned() const = 0;
		virtual int				getGradeToExecute() const = 0;
		virtual std::string		getName() const = 0;
		virtual bool			getSigned() const = 0;

		virtual void	beSigned(Bureaucrat &other) = 0;
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw(){
				return ("Form Grade too high !");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw(){
			return ("Form Grade too low !");
		}
	};
};

std::ostream& operator<<(std::ostream &fd, const AForm &other);

#endif
