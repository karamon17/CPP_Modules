/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:14:06 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/08 17:23:48 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombiedefault;
	zombiedefault.announce();

	Zombie *zombie = newZombie("Zombie in heap");
	zombie->announce();
	
	randomChump("Zombie in stack");
	delete zombie;
	return (0);
}