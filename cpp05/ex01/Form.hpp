/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:35:24 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/06 12:28:52 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <ostream>

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool 				_signed;
		const int 			_gradeToSigned;
		const int			_gradeToExecute;
		Form();
	public:
		~Form();
		Form(std::string, int, int);
		Form& operator=(const Form &other);

		int				getGradeToSigned() const;
		int				getGradeToExecute() const;
		std::string		getName() const;
		bool			getSigned() const;
		void			setSigned(bool);

		void	beSigned(Bureaucrat &other);
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

std::ostream& operator<<(std::ostream &fd, const Form &other);

#endif
