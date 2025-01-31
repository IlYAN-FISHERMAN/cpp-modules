/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:09:08 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/31 21:35:00 by ilyanar          ###   LAUSANNE.ch       */
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
	long id;
	s_date();
	s_date(int, int, int, int);
	bool operator<(const s_date& other) const {
        if (year != other.year)
			return year < other.year;
        if (month != other.month)
			return month < other.month;
        if (day != other.day)
			return day < other.day;
        return id < other.id;
    }
	bool operator<=(const s_date& other) const {
        if (year != other.year)
			return year <= other.year;
        if (month != other.month)
			return month <= other.month;
        return day <= other.day;
    }
	bool operator>(const s_date& other) const {
        if (year != other.year)
			return year > other.year;
        if (month != other.month)
			return month > other.month;
        return day > other.day;
    }
	bool operator==(const s_date& other) const {
        if (year == other.year && month == other.month && day == other.day)
			return true;
		return false;
    }
} t_date;

# ifndef DEBUG
#  define DEBUG 0
# endif
# define its std::map<t_date, float>::iterator
# define itm std::map<int, int>::iterator
# define itl std::map<int, std::map<t_date, float> >::iterator

class Btc
{
	private:
		std::ifstream _inputFile;
		std::ifstream _dataFile;
		std::map<int, std::map<t_date, float> > _input;
		std::map<int, std::map<t_date, float> > _data;
		std::map<int, int> _month;
		Btc();
	public:
		~Btc();
		Btc(const char *input, const char *data);
		Btc(const Btc &other);
		Btc& operator=(const Btc &other);

		void	parseData();
		void	parseInput();
		void	compareInput();

		std::ifstream& getInputFile();
		std::ifstream& getDataFile();

		int		dateCompare(const std::string, const std::string);
		tm		dateTime(const char *date, const char* format);

		class ToManyInformationException : public std::exception{
				const char* what() const throw(){return ("Too much/less information");}
	};
};

bool is_data_value(const char *input);
#endif
