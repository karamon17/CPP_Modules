/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:25:32 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/08 19:29:15 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon &weapon)
{
	this->weapon = &weapon;
};

HumanA::~HumanA()
{

};

void HumanA::setName(std::string name)
{
	this->name = name;
}

void HumanA::attack(std::string name, Weapon &weapon)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}