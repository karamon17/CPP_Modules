#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	this->_type = type;
}

AMateria::AMateria(const AMateria &copy) {
	_type = copy._type;
}

AMateria &AMateria::operator=(const AMateria &copy) {
	if (this == &copy) {
		std::cout << "Materia is same" << std::endl;
		return *this;
	}
	std::cout<< "you cannot assign different materia" << std::endl;
	return *this;
}

AMateria::~AMateria() {
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}

AMateria::AMateria()
{

}