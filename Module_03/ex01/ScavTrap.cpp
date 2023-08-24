#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	name = "default ScavTrap";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& tocopy) : ClapTrap(tocopy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& tocopy) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	ClapTrap::operator=(tocopy);
	return (*this);
}

ScavTrap::~ScavTrap() { 
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (energyPoints && hitPoints) {
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "Trap can't do anything, it has no points" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " has entered in Gate keeper mode" << std::endl;
}