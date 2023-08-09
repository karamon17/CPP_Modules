/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:25:32 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/09 14:48:39 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->weapon = &weapon;
	this->name = name;
};

HumanA::~HumanA()
{

};

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}