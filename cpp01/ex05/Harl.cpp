/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:24:11 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/15 14:08:01 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl(void){
	_cmd[0] = "DEBUG";
	_cmd[1] = "INFO";
	_cmd[2] = "WARNING";
	_cmd[3] = "ERROR";
	_func[0] = &Harl::debug;
	_func[1] = &Harl::info;
	_func[2] = &Harl::warning;
	_func[3] = &Harl::error;
}

Harl::~Harl(){}

void Harl::debug( void ){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ){
	std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void Harl::complain( std::string level ){
	for (int d = 0; !_cmd[d].empty(); d++){
		if (!_cmd[d].compare(level)){
			(this->*_func[d])();
			break ;
		}
		else if (d + 1 == LVL_LEN)
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
