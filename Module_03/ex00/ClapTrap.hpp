#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
		ClapTrap();

	public:
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap(const ClapTrap& tocopy);
		ClapTrap& operator=(const ClapTrap& tocopy);
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif