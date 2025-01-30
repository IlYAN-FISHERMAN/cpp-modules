/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:09:08 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/30 02:25:57 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <map>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <strings.h>

typedef struct s_date
{
	int year;
	int month;
	int	day;
	s_date();
	s_date(int, int, int);
	bool operator<(const s_date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
} t_date;

# define its std::map<t_date, float>::iterator
# define itl std::map<int, std::map<t_date, float> >::iterator

class Btc
{
	private:
		std::ifstream _inputFile;
		std::ifstream _dataFile;
		std::map<int, std::map<t_date, float> > _input;
		std::map<int, std::map<t_date, float> > _data;
		std::map<int, double> _month;
		Btc();
	public:
		~Btc();
		Btc(const char *input, const char *data);
		Btc(const Btc &other);
		Btc& operator=(const Btc &other);

		void parseData();
		void parseInput();
		std::ifstream& getInputFile();
		std::ifstream& getDataFile();
		std::map<std::string, double>::iterator& getInput();
		std::map<std::string, double>::iterator& getData();
		int		dateCompare(const std::string, const std::string);
		tm		dateTime(const char *date, const char* format);
		void	addToData(std::string);
		void	addToInput(std::string);

		class ToManyInformationException : public std::exception{
			const char* what() const throw();
	};
};

bool is_data_value(const char *input);

#endif
