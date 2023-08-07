/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:46:33 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/07 17:04:51 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::welcome(void) const
{
	std::cout << "Welcome to the PhoneBook!" << std::endl;
	std::cout << "Please, enter one of the following commands:" << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "EXIT" << std::endl;
}

void PhoneBook::add(void)
{
    static int  i;
    _contacts[i % 8].init();
    _contacts[i % 8].setIndex(i % 8);
    i++;
}

void    PhoneBook::print(void) const {
    std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
    for (size_t i = 0; i < 8; i++) {
        _contacts[i].view(i);
    }
    std::cout << std::endl;
}

int     PhoneBook::read_input() const {
    int     input = -1;
    bool    valid = false;
    do
    {
        std::cout << "Please enter the contact index: " << std::flush;
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 8)) {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        } else {
            //something went wrong, we reset the buffer's state to good
            std::cin.clear();
            //and empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid index; please re-enter." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    PhoneBook::search(void) const {
    int i = read_input();
	_contacts[i].display(i);
}