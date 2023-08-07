/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:46:31 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/07 16:15:25 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    PhoneBook book;
    std::string input = "";
    book.welcome();
    while (input.compare("EXIT")) {
        if (input.compare("ADD") == 0)
            book.add();
        else if (input.compare("SEARCH") == 0) {
            book.print();
            book.search();
        }
        std::cout << "> " << std::flush;
        std::cin >> input;
    }
    return 0;
}