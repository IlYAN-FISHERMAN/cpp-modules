/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:09:58 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/03 19:31:04 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
# define PPF_GRADE_SIGNED 25
# define PPF_GRADE_EXECUTE 5

#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		void		_formAction() const;
	public:
		PresidentialPardonForm(std::string);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const & executor) const;
};

#endif
