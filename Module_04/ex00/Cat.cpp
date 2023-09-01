#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &copy)
        Animal::operator=(copy);
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}