#include "Ice.hpp"

Ice::Ice() {
	_type = "ice";
}

Ice::Ice(const Ice &copy) {
	_type = copy._type;
}

Ice &Ice::operator=(const Ice &copy) {
	if (this != &copy)
		AMateria::operator=(copy);
	return *this;
}

Ice::~Ice() {
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}