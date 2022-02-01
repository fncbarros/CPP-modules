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

int	Account::_nbAccounts; // need initialize?
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

/*Constructors*/

Account::Account( void ) {
	this->_accountIndex = getNbAccounts();
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
} ;

Account::Account( int initial_deposit) {
	// cout << "Constructor called." << endl;
	Account();
	this->_amount = initial_deposit; // ??
} ;

/*Account::Account( int initial_deposit): amount(initial_deposit)*/ /*??*/
/*{
	// cout << "Constructor called." << endl;
	this->_amount = initial_deposit;
} ;*/

/*Destructor*/

Account::~Account( void ) {
	_nbAccounts--;
	_totalAmount -= _amount;
} ;

/*Functions members*/
int	Account::getNbAccounts( void ) {
//	static int nbAccounts = this->_nbAccounts;
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
	/*[display_time] accounts:n;total:n;deposits:n;withdrawals:n*/
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts(); // must be relative to specific object (class instance ??)
	std::cout << ";total:" << getTotalAmount();
//	std::cout << _totalNbWithdrawals; // valid ?? <------------------- [!]
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
} ;

void	Account::makeDeposit( int deposit ) {
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
} ;

bool	Account::makeWithdrawal( int withdrawal ) {
	if (0 > (_amount - withdrawal))
		return (false);
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	return (true);
} ;

int		Account::checkAmount( void ) const {
	return (_amount);
} ;

void	Account::displayStatus ( void ) const {
	/**format to include "[] ;"
	 *
	*/
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";" << std::endl;
} ;

void	Account::_displayTimestamp( void ) {
	time_t	now = std::time(0);
	struct tm	*ps_time = localtime(&now);
	ps_time = std::gmtime(&now);
	std::cout << "[" << 1900 + ps_time->tm_year; // year since 1900
	std::cout << std::setfill('0') << std::setw(2); // padding with '0' and setting width
	std::cout << 1 + ps_time->tm_mon;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ps_time->tm_mday << "_";
	std::cout << ps_time->tm_hour << ps_time->tm_min << ps_time->tm_sec << "] ";
} ;
