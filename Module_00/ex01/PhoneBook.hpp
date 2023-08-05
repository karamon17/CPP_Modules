/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:46:02 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/05 14:19:23 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];
	int read_input(void) const;
public:
	PhoneBook();
	~PhoneBook();
	void add(void);
	void search(void) const;
	void print(void) const;
	void welcome(void) const;
};

#endif