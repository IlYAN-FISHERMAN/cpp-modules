/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:16:40 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/28 09:32:53 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>

Btc::~Btc(){
	if (!_inputFile.is_open())
		_inputFile.close();
	if (!_dataFile.is_open())
		_dataFile.close();
}

Btc::Btc(const char *input, const char *data){
	_inputFile.open(input);
	_dataFile.open(data);
	if (!_inputFile.is_open() || !_dataFile.is_open()){
		if (!_inputFile.is_open())
			throw (std::runtime_error("Input file can\'t be open"));
		else
			throw (std::runtime_error("data file can\'t be open"));
	}
}

Btc::Btc(const Btc &other){
	(void)other;
}

Btc& Btc::operator=(const Btc &other){
	(void)other;
	return *this;
}

std::ifstream& Btc::getInput(){return (_inputFile);}

std::ifstream& Btc::getData(){return (_dataFile);}
