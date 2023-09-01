#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{	
	private:
    	ScavTrap();

	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap& tocopy);
		ScavTrap& operator=(const ScavTrap& tocopy);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate();
};

#endif