/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:45:57 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/07 16:06:19 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	int			_index;

	std::string _printLen(std::string str) const;
    std::string _getInput(std::string str) const;
public:
	Contact() {};
	~Contact() {};
	void    init(void);
    void    view(int index) const;
    void    display(int index) const;
    void    setIndex(int i);
};

#endif