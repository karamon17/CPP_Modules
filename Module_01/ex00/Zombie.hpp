/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:14:36 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/08/08 16:52:09 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie(/* args */);
	~Zombie();
	void announce( void );
	void setName( std::string name );
};

	Zombie* newZombie( std::string name );
	void randomChump( std::string name );

#endif