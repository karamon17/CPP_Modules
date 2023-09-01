#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap() { 
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& tocopy) {
	*this = tocopy;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& tocopy) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = tocopy.name;
	this->hitPoints = tocopy.hitPoints;
	this->attackDamage = tocopy.attackDamage;
	this->energyPoints = tocopy.energyPoints;
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints && hitPoints) {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "Trap can't do anything, it has no points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return;
	}
	if (amount > hitPoints) {
		std::cout << "ClapTrap " << name << " takes " << hitPoints << " damage" << std::endl;
		hitPoints = 0;
	} else {
		std::cout << "ClapTrap " << name << " takes " << amount << " damage" << std::endl;
		hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints && hitPoints) {
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " is repaired for " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "Trap can't do anything, it has no points" << std::endl;
}