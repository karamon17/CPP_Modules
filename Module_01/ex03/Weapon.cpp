/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:25:23 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/08 20:24:39 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon()
{

}

Weapon::~Weapon()
{
	
}

const std::string& Weapon::getType(void)
{
	return (type);
}
void Weapon::setType(std::string type)
{
	this->type = type;
}