/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:50:36 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/13 16:30:21 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <_strings.h>
#include <ctime>
#include <functional>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit ){
	_accountIndex = _nbAccounts;
	++_nbAccounts;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	std::cout << "checkAmount" << std::endl;
	return (1);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
	if (_accountIndex == _nbAccounts - 1)
		std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);

    std::cout << "[" << localTime->tm_year + 1900 << localTime->tm_mon + 1
		<< localTime->tm_mday << "_" << localTime->tm_hour << localTime->tm_min
		<< localTime->tm_sec << "] ";
}

int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	std::cout << std::endl;
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
	std::cout << std::endl;
}
