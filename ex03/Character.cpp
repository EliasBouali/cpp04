#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(const std::string &name)
:name(name)
{
  for (int i = 0; i < 4; i++)
    this->inventory[i] = 0;
}

Character::Character(const Character &other)
:name(other.name)
{
  for (int i = 0; i < 4; i++)
    this->inventory[i] = 0;
  *this = other;
}

Character& Character::operator=(const Character &other)
{
  if (this != &other)
  {
    this->name = other.name;
    for (int i = 0; i < 4; i++)
    {
      if (this->inventory[i])
      {
        delete this->inventory[i];
        this->inventory[i] = 0;
      }
    }
    for (int i = 0; i < 4; i++)
    {
      if (other.inventory[i])
        this->inventory[i] = other.inventory[i]->clone();
      else
        this->inventory[i] = 0;
    }
  }
  return *this;
}

Character::~Character()
{
  for (int i = 0; i < 4; i++)
  {
    if (this->inventory[i])
      delete this->inventory[i];
  }
}

std::string const & Character::getName() const
{
  return this->name;
}

void Character::equip(AMateria *m)
{
  if (!m)
    return ;

  for (int i = 0; i < 4; i++)
  {
    if (!this->inventory[i])
    {
      this->inventory[i] = m;
      return ;
    }
  }
}

void Character::unequip(int idx)
{
  if (idx < 0 || idx >= 4)
    return ;

  this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
  if (idx < 0 || idx >= 4)
    return ;

  if (this->inventory[idx])
    this->inventory[idx]->use(target);
}
