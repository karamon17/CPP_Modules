/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:25:28 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/08 19:29:05 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{

};

HumanB::~HumanB()
{

};

void HumanB::setName(std::string name)
{
	this->name = name;
}

void HumanB::attack(std::string name, Weapon &weapon)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}