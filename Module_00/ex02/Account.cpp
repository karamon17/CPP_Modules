/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:47:49 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/08 11:27:28 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
	
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}
int	Account::getTotalAmount( void ) {
	return _totalAmount;
}
int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";" << "total:" << _totalAmount << ";" << "deposits:" << _totalNbDeposits << ";" << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) {
	_displayTimestamp();
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
};

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
};

void	Account::makeDeposit( int deposit ) {
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal ) {
	if (_amount < withdrawal)
		return false;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	return true;
}
int		Account::checkAmount( void ) const {
	return _amount;
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "deposits:" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t currentTime = time(NULL);
	struct tm *localTime = localtime(&currentTime);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buffer << " ";
}