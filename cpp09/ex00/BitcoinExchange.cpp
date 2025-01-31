/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:16:40 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/31 22:08:21 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

s_date::s_date() : year(0), month(0), day(0), id(0){}

s_date::s_date(int y, int m, int d, int i) : year(y), month(m), day(d), id(i){}

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
	Btc::parseInput();
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
	t_date	tmp;
	std::stringstream stream(date);
	char sep = 0;
	std::string str;

	bzero(&tm, sizeof(tm));
	stream >> tmp.year >> sep >> tmp.month >> sep >> tmp.day >> str;
    if(!strptime(date, format, &tm) || !str.empty() || tmp.year < 0
		|| tmp.year > 2050 || tmp.month > 12
		|| tmp.month < 0 || tmp.day < 0){
		std::cerr << "\"" << date << "\": ";
		throw std::runtime_error("Bad date format: <%Y-%m-%d>");
	}
	tm.tm_year += 1900;
	tm.tm_mon += 1;
	itm ite = _month.begin();
	for (;ite->first != tmp.month; ite++)
		;
	if (ite->first == 2 && !(tmp.year % 4)){
		if (!(tmp.year % 100) && (tmp.year % 400)){
			std::cerr << "\"" << date << "\": ";
			throw std::runtime_error("Bad bisextile date format: <%Y-%m-%d>");
		}
		ite->second = 29;
	}
	if (tmp.day > ite->second){
		std::cerr << "\"" << date << "\": ";
		throw std::runtime_error("Bad day format: <%Y-%m-%d>");
	}
    return tm;
}

void Btc::parseInput(){
	std::string input;
	std::string dateFormat;
	float value = 0;
	long id = 0;

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
			if (!end.empty() || lseparator.empty() || lseparator != "|" || *tmp || nbr.empty()){
				std::cerr << "\"" << input << "\": ";
				throw (ToManyInformationException());
			}
			else if (value < 0 || value > 1000){
				std::cerr << "\"" << value << "\": ";
				throw std::runtime_error("Bad Value format");
			}
			itl it = _input.find(tm.tm_year);
			if (it == _input.end()){
				std::map<t_date, float> new_map;
				new_map.insert(std::make_pair(t_date(tm.tm_year, tm.tm_mon, tm.tm_mday, id), value));
				_input.insert(std::make_pair(tm.tm_year, new_map));
			}
			else{
				it->second.insert(std::make_pair(t_date(tm.tm_year, tm.tm_mon, tm.tm_mday, id), value));
			}
			id++;
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

void	Btc::compareInput(){

	itl input = _input.begin();
	std::cout << std::fixed << std::setprecision(2);
	for (; input != _input.end(); input++){
		for (its in = input->second.begin(); in != input->second.end(); in++){
			its print = _data.end()->second.end();
			for (itl data = _data.begin(); data != _data.end(); data++){
				for (its da = data->second.begin(); da != data->second.end(); da++){
					if (da->first <= in->first){
						if (print == _data.end()->second.end())
							print = da;
						else if (da->first > print->first)
							print = da;
					}
					if (print->first == in->first)
						break ;
				}
			}
			std::cout << in->first.year << "-"
				<< in->first.month << "-"
				<< in->first.day << " => "
				<< in->second << " = "
				<< (double)(in->second * print->second) << std::endl;
			if (DEBUG){
				std::cout << "date founded: " << print->first.year << "-"
				<< print->first.month << "-"
				<< print->first.day << " | " << print->second << std::endl << std::endl;
			}
		}
	}
}
