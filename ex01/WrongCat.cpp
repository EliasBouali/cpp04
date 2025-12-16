#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
  this->type = "WrongCat";
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
  std::cout << "[WrongCat] Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.type;
  return *this;
}

WrongCat::~WrongCat()
{
  std::cout << "[WrongCat] Destructor called" << std::endl;

}

void WrongCat::makeSound() const
{
  std::cout << "WrongCat Miaou?? (wrong)" << std::endl;
}
