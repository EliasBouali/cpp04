#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
  this->type = "WrongAnimal";
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
  std::cout << "[WrongAnimal] Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.type;
  return *this;
}

WrongAnimal::~WrongAnimal()
{
  std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
  return this->type;
}

void WrongAnimal::makeSound() const
{
  std::cout << "WrongAnimal, wrong genetic sound " << std::endl;
}
