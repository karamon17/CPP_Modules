#include "Character.hpp"

AMateria *GROUND[100];
int GROUND_COUNT = 0;
void PutOnGround(AMateria *materia)
{
	GROUND[GROUND_COUNT] = materia;
	GROUND_COUNT++;
}

Character::Character() : ICharacter() {
	name = "Character";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	count = 0;
}

Character::Character(std::string name) : ICharacter() {
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	count = 0;
}

Character::Character(const Character &copy) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	*this = copy;
}

Character &Character::operator=(const Character &copy) {
	if (this == &copy)
		return *this;
	name = copy.name;
	for (int i = 0; i < copy.count; i++)
	{
		if (inventory[i]) {
			delete inventory[i];
			inventory[i] = NULL;
		}
		inventory[i] = copy.inventory[i]->clone();
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (inventory[i] != NULL)
			delete inventory[i];
}

std::string const &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			inventory[i] = m;
			++count;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !count || !inventory[idx])
		return;
	--count;
	PutOnGround(inventory[idx]);
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
		inventory[idx]->use(target);
}