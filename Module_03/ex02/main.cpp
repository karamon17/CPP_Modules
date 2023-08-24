#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
	std::cout << "Test ClapTrap" << std::endl;
	{
		ClapTrap aaa("aaa");
		ClapTrap bbb("bbb");
		aaa.attack("bbb");
		bbb.takeDamage(3);
		aaa.attack("bbb");
		bbb.takeDamage(3);
		bbb.beRepaired(3);
	}
	std::cout << "Test ScavTrap" << std::endl;
	{
		ScavTrap aaa("aaa");
		ScavTrap bbb("bbb");
		aaa.attack("bbb");
		bbb.takeDamage(3);
		aaa.attack("bbb");
		bbb.takeDamage(3);
		bbb.beRepaired(3);
		bbb.guardGate();
	}
	std::cout << "Test FragTrap" << std::endl;
	{
		FragTrap aaa("aaa");
		FragTrap bbb("bbb");
		aaa.highFivesGuys();
		aaa.attack("bbb");
		bbb.takeDamage(3);
		aaa.attack("bbb");
		bbb.takeDamage(3);
		bbb.highFivesGuys();
	}
	return (0);
}