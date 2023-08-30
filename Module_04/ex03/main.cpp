#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "### ICE TESTS ###" << std::endl;
	{
		AMateria *ice = new Ice();
		AMateria *clone;
		ICharacter *villain = new Character("villain");

		clone = ice->clone();
		std::cout << "Ice type: " << clone->getType() << std::endl;
		std::cout << "Clone type: " << clone->getType() << std::endl;
		std::cout << "Using type: ";
		ice->use(*villain);

		delete villain;
		delete clone;
		delete ice;
	}
	std::cout << "\n### CURE TESTS ###" << std::endl;
	{
		AMateria *cure = new Cure();
		AMateria *clone;
		ICharacter *hero = new Character("hero");

		clone = cure->clone();
		std::cout << "Cure type: " << clone->getType() << std::endl;
		std::cout << "Clone type: " << clone->getType() << std::endl;
		std::cout << "Using type: ";
		cure->use(*hero);

		delete hero;
		delete clone;
		delete cure;
	}
	std::cout << "\n### CHARACTER TESTS ###" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		ICharacter *me = new Character("me");

		std::cout << "Character name: " << me->getName() << std::endl;
		std::cout << "Equiping materia..." << std::endl;
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "Unequiping materia..." << std::endl;
		me->unequip(0);
		me->unequip(1);

		delete me;
		delete src;
	}
	std::cout << "\n### MANDATORY TESTS ###" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	//system("leaks game");
	return (0);
}