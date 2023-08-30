#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	count = 0;
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
	std::cout << count << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	if (this != &copy)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (materia[i])
				delete materia[i];
			materia[i] = copy.materia[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (materia[i])
			delete materia[i];
}

void MateriaSource::learnMateria(AMateria *m) {
	if (count < 4)
	{
		materia[count] = m;
		count++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] != NULL && materia[i]->getType() == type)
			return materia[i]->clone();
	}
	std::cout << "cannot create materia" << std::endl;
	return NULL;
}