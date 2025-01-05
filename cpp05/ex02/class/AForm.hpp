/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:35:24 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/05 20:35:19 by ilyanar          ###   LAUSANNE.ch       */
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
	public:
		virtual ~AForm() = 0;
		AForm(std::string, int, int);

		int				getGradeToSigned() const;
		int				getGradeToExecute() const;
		std::string		getName() const;
		bool			getSigned() const;

		void			setSigned(bool);
		void			beSigned(Bureaucrat &other);
		void			printForm() const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

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


#endif
