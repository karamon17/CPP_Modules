#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap aaa("aaa");
	DiamondTrap bbb("bbb");
	aaa.whoAmI();
	aaa.highFivesGuys();
	aaa.attack("bbb");
	bbb.whoAmI();
	bbb.takeDamage(3);
	aaa.attack("bbb");
	bbb.takeDamage(3);
	bbb.highFivesGuys();
	bbb.guardGate();
	return (0);
}