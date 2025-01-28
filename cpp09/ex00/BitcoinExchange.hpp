/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:09:08 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/28 09:33:02 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
class Btc
{
	private:
		std::ifstream _inputFile;
		std::ifstream _dataFile;
		Btc();
	public:
		~Btc();
		Btc(const char *input, const char *data);
		Btc(const Btc &other);
		Btc& operator=(const Btc &other);
		std::ifstream& getInput();
		std::ifstream& getData();
};

#endif
