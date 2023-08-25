#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap aaa("aaa");
	ScavTrap bbb("bbb");
	aaa.attack("bbb");
	bbb.takeDamage(3);
	aaa.attack("bbb");
	bbb.takeDamage(3);
	bbb.beRepaired(3);
	bbb.guardGate();
	return (0);
}