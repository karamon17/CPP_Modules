#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{	
	private:
    	FragTrap();

	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap& tocopy);
		FragTrap& operator=(const FragTrap& tocopy);
		~FragTrap();

		void highFivesGuys(void);
};

#endif