/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:22:36 by ilyanar           #+#    #+#             */
/*   Updated: 2025/02/02 16:45:30 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

Rpn::Rpn(){}

Rpn::~Rpn(){}

Rpn& Rpn::operator=(const Rpn &other){
	if (this != &other)
		_stack = other._stack;
	return *this;
}

Rpn::Rpn(const Rpn &other) : _stack(other._stack){}

Rpn::Rpn(std::string str){

	char *tmp = NULL;
	std::string value;

	std::reverse(str.begin(), str.end());
	std::stringstream stream(str);
	while (stream >> value){
		std::reverse(value.begin(), value.end());
		if (isOperator(value))
			_stack.push(value);
		else{
			if ((std::strtol(value.c_str(), &tmp, 10)) > 9 || *tmp){
				std::cerr << "Bad input: " << value << std::endl;
				throw std::runtime_error("Not a valid operator/operand");
			}
			_stack.push(value);
			tmp = NULL;
		}
	}
}

bool Rpn::isOperator(std::string &ope) const{

	if (ope == "*" || ope == "/" || ope == "+" || ope == "-")
		return true;
	return false;
}

void Rpn::showStack() const{

	std::stack<std::string> s(_stack);
	std::cout << "Stack (top to bottom) :" << std::endl;
	for (int i = 0; !s.empty(); i++){
		std::cout << "[" << i << "]: " << "\"" << s.top() << "\"" << std::endl;
		s.pop();
	}
	std::cout << std::endl << "END" << std::endl << std::endl;
}

void Rpn::calculeStack() const{

	std::stack<long int> nbr;
	std::stack<std::string> tmp(_stack);
	long int nb1 = 0;
	long int nb2 = 0;
	char *str = NULL;

	while (!tmp.empty()){
		while (!tmp.empty() && !isOperator(tmp.top())){
			nbr.push(std::strtol(tmp.top().c_str(), &str, 10));
			tmp.pop();
		}
		if (tmp.empty() || !isOperator(tmp.top()))
			throw std::runtime_error("Missing operator after operand");
		if (isOperator(tmp.top())){
			if (!nbr.empty()){
				nb2 = nbr.top();
				nbr.pop();
			}
			else{
				std::cerr << "operator: \"" << tmp.top() << "\"" << std::endl;
				throw std::runtime_error("Missing operand before operator");
			}
			if (!nbr.empty()){
				nb1 = nbr.top();
				nbr.pop();
			}
			else{
				std::cerr << "operator: \"" << tmp.top() << "\"" << std::endl;
				throw std::runtime_error("Expected operand before operator");
			}
		}
		if (!tmp.empty()){
			if (tmp.top() == "*")
				nb1 *= nb2;
			else if (tmp.top() == "-")
				nb1 -= nb2;
			else if (tmp.top() == "+")
				nb1 += nb2;
			else if (tmp.top() == "/"){
				if (nb2 == 0)
					throw std::runtime_error("Division by 0 is undefined");
				nb1 /= nb2;
			}
			tmp.pop();
			nbr.push(nb1);
			if (tmp.empty())
				break ;
		}
		else
			throw std::runtime_error("Not enought information in the stack");
	}
	if (nbr.size() != 1)
		throw std::runtime_error("Not enought information in the stack");
	std::cout << nbr.top() << std::endl;
}
