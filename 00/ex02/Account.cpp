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
# include <ctime>

/*Constructors*/

Account::Account( void ) {
	_amount = 0;
	_nbDeposits = 0;
} ;

Account::Account( int initial_deposit) {
	// cout << "Constructor called." << endl;
	this->_amount = initial_deposit; // ??
} ;

/*Account::Account( int initial_deposit): amount(initial_deposit) /*??*/
/*{
	// cout << "Constructor called." << endl;
	this->_amount = initial_deposit;
} ;*/

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
	_displayTimestamp();
	std::cout << " index:" << _accountIndex; // must be relative to specific object (class instance ??)
	std::cout <<
} ;

void	Account::makeDeposit( int deposit ) {
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
} ;

bool	Account::makeWithdrawal( int withdrawal ) {
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
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
	std::cout << ";"
} ;

void	Account::_displayTimestamp( void ) {
	
} ;
