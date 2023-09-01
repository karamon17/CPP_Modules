#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{	
	private:
		DiamondTrap();
		std::string name;

	public:
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap& tocopy);
		DiamondTrap& operator=(const DiamondTrap& tocopy);
		~DiamondTrap();

		void attack(const std::string &target);
		void whoAmI();
};

#endif