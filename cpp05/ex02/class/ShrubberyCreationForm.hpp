/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:28:19 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 19:05:34 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include "Bureaucrat.hpp"

# define SCF_GRADE_SIGNED 145
# define SCF_GRADE_EXECUTE 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		void		_formAction() const;
	public:
		ShrubberyCreationForm(std::string);
		~ShrubberyCreationForm();
		
		void	execute(Bureaucrat const & executor) const;
};

#endif
