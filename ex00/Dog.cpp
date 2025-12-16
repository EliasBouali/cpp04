#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog Wouf! Wouf!" << std::endl;
}
