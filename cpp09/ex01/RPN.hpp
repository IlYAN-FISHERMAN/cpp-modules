/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:25:12 by ilyanar           #+#    #+#             */
/*   Updated: 2025/02/02 15:38:13 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>

#ifndef DEBUG
# define DEBUG 0
#endif

class Rpn
{
	private:
		std::stack<std::string> _stack;
		Rpn();
	public:
		~Rpn();
		Rpn& operator=(const Rpn &other);
		Rpn(const Rpn &other);
		Rpn(std::string);

		void calculeStack() const;
		bool isOperator(std::string &ope) const;
		void showStack() const;
};

#endif
