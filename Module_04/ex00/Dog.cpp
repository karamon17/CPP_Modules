#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &copy)
        Animal::operator=(copy);
    return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}