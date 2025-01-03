/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:07:55 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 19:21:17 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# define RRF_GRADE_SIGNED 72
# define RRF_GRADE_EXECUTE 45

#include <iostream>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		void		_formAction() const;
	public:
		RobotomyRequestForm(std::string);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const & executor) const;
};

#endif
