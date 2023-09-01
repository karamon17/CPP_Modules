#include "ClapTrap.hpp"

int main()
{
	ClapTrap aaa("aaa");
	ClapTrap bbb("bbb");
	aaa.attack("bbb");
	bbb.takeDamage(3);
	aaa.attack("bbb");
	bbb.takeDamage(3);
	bbb.beRepaired(3);
	return (0);
}