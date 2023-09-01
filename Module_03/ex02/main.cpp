#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap aaa("aaa");
	FragTrap bbb("bbb");
	aaa.highFivesGuys();
	aaa.attack("bbb");
	bbb.takeDamage(3);
	aaa.attack("bbb");
	bbb.takeDamage(3);
	bbb.highFivesGuys();
	return (0);
}