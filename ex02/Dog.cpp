#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    std::cout << "[Dog] Copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[Dog] Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "[Dog] Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Wouf! Wouf!" << std::endl;
}

