/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:46:28 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/07 16:06:26 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::_getInput(std::string str) const
{
    std::string input = "";
    bool        valid = false;
    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else 
		{
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    Contact::init(void)
{
	std::cin.ignore();
    _first_name = _getInput("Please enter you first name: ");
    _last_name = _getInput("Please enter your last name: ");
    _nickname = _getInput("Please enter your nickname: ");
    _phone_number = _getInput("Please enter your phone number: ");
    _darkest_secret = _getInput("Please enter your darkest secret: ");
    std::cout << std::endl;
}

std::string Contact::_printLen(std::string str) const 
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::view(int index) const
{
	if (_first_name.empty() || _last_name.empty() || _nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << _printLen(_first_name) << std::flush;
    std::cout << "|" << std::setw(10) << _printLen(_last_name) << std::flush;
    std::cout << "|" << std::setw(10) << _printLen(_nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::display(int index) const
{
	if (_first_name.empty() || _last_name.empty() || _nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
    std::cout << "First Name:\t" << _first_name << std::endl;
    std::cout << "Last Name:\t" << _last_name << std::endl;
    std::cout << "Nickname:\t" << _nickname << std::endl;
    std::cout << std::endl;
}

void    Contact::setIndex(int i)
{
	Contact::_index = i;
}