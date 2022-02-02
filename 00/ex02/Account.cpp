/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <fbarros@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:59:25 by fbarros           #+#    #+#             */
/*   Updated: 2022/01/28 11:59:50 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
# include <iostream>
# include <iomanip>
# include <ctime>

/*static Members*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*Constructors*/

Account::Account( void ) {
	_accountIndex = _nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
} ;

Account::Account( int initial_deposit) {
	/* calling default Constructor from here applied no difference to indexes (??)*/
	_accountIndex = _nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
} ;

/*Destructor*/

Account::~Account( void ) {
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
} ;

/*Functions members*/
int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
} ;

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
} ;

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
} ;

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
} ;

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
} ;

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
} ;

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (0 > (_amount - withdrawal)) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
} ;

int		Account::checkAmount( void ) const {
	return (_amount);
} ;

void	Account::displayStatus ( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
} ;

void	Account::_displayTimestamp( void ) {
	time_t	now = std::time(0);
	struct tm	*ps_time = localtime(&now);
	ps_time = std::gmtime(&now);
	/*year since 1900*/
	std::cout << "[" << 1900 + ps_time->tm_year;
	std::cout << std::setfill('0') << std::setw(2);
	/*tm_mon starts at month 0*/
	std::cout << 1 + ps_time->tm_mon;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ps_time->tm_mday << "_";
	std::cout << ps_time->tm_hour << ps_time->tm_min << ps_time->tm_sec << "] ";
} ;







