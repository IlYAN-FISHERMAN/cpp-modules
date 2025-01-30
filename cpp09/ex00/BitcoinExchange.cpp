/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:16:40 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/30 15:53:46 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <utility>

s_date::s_date() : year(0), month(0), day(0){}

s_date::s_date(int y, int m, int d) : year(y), month(m), day(d){}

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
	Btc::parseData();
	Btc::parseInput();
	_month.insert(std::make_pair(1, 31));
	_month.insert(std::make_pair(2, 28));
	_month.insert(std::make_pair(3, 31));
	_month.insert(std::make_pair(4, 30));
	_month.insert(std::make_pair(5, 31));
	_month.insert(std::make_pair(6, 30));
	_month.insert(std::make_pair(7, 31));
	_month.insert(std::make_pair(8, 31));
	_month.insert(std::make_pair(9, 30));
	_month.insert(std::make_pair(10, 31));
	_month.insert(std::make_pair(11, 30));
	_month.insert(std::make_pair(12, 31));
}

Btc::Btc(const Btc &other){
	(void)other;
}

Btc& Btc::operator=(const Btc &other){
	(void)other;
	return *this;
}

std::ifstream& Btc::getInputFile(){return (_inputFile);}

std::ifstream& Btc::getDataFile(){return (_dataFile);}

tm Btc::dateTime(const char *date, const char* format)
{
	tm tm;
	bzero(&tm, sizeof(tm));
    if(!strptime(date, format, &tm))
		throw std::runtime_error("Bad date format, <%Y-%m-%d>");
	tm.tm_year += 1900;
	tm.tm_mon += 1;

    return tm;
}

void Btc::parseInput(){
	std::string input;
	std::string dateFormat;
	float value = 0;

	for (long i = 0; std::getline(_inputFile, input); i++){
		if (i <= 0 && !is_data_value(input.c_str()))
			throw std::runtime_error("\033[31mNo \"data | value\" header detected\033[0m");
		else if (i >= 1){
			std::stringstream stream(input);
			std::string lseparator("");
			std::string end("");
			std::string nbr("");
			char *tmp;

			stream >> dateFormat >> lseparator >> nbr >> end;
			tm tm = dateTime(dateFormat.c_str(), "%Y-%m-%d");
			value = strtod(nbr.c_str(), &tmp);
			if (!end.empty() || lseparator.empty() || tmp)
				throw (ToManyInformationException());
			itl it = _input.find(date.year);
			if (it == _input.end()){
				std::map<t_date, float> new_map;
				new_map.insert(std::make_pair(date, value));
				_input.insert(std::make_pair(date.year, new_map));
			}
			else{
				it->second.insert(std::make_pair(date, value));
			}
		}
	}
}

void Btc::parseData(){
	std::string input;
	t_date date;
	char separator = 0;
	float value = 0;

	for (long i = 0; std::getline(_dataFile, input); i++){
		if (i <= 0)
			;
		else if (i >= 1){
			std::stringstream stream(input);

			stream >> date.year >> separator >> date.month >> separator >> date.day >> separator >> value;
			itl it = _data.find(date.year);
			if (it == _data.end()){
				std::map<t_date, float> new_map;
				new_map.insert(std::make_pair(date, value));
				_data.insert(std::make_pair(date.year, new_map));
			}
			else{
				it->second.insert(std::make_pair(date, value));
			}
		}
	}
}
