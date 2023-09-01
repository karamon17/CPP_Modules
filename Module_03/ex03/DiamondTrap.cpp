#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
	std::cout << "DiamondTrap name constructor called" << std::endl;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& tocopy) : ClapTrap(tocopy), FragTrap(tocopy), ScavTrap(tocopy) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	name = tocopy.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& tocopy) {
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	this->ClapTrap::operator=(tocopy);
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}