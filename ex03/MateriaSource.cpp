#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
  for (int i = 0; i < 4; i++)
    this->_templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
  for (int i = 0; i < 4; i++)
    this->_templates[i] = 0;
  *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
  if (this != &other)
  {
    for (int i = 0; i < 4; i++)
    {
      if (this->_templates[i])
      {
        delete this->_templates[i];
        this->_templates[i] = 0;
      }
    }

    for (int i = 0; i < 4; i++)
    {
      if (other._templates[i])
        this->_templates[i] = other._templates[i]->clone();
      else
        this->_templates[i] = 0;
    }
  }
  return *this;
}

MateriaSource::~MateriaSource()
{
  for (int i = 0; i < 4; i++)
  {
    if (this->_templates[i])
      delete this->_templates[i];
  }
}

void MateriaSource::learnMateria(AMateria *m)
{
  if (!m)
    return ;

  for (int i = 0; i < 4; i++)
  {
    if (!this->_templates[i])
    {
      this->_templates[i] = m;
      return ;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
  for (int i = 0; i < 4; i++)
  {
    if (this->_templates[i] && this->_templates[i]->getType() == type)
      return this->_templates[i]->clone();
  }
  return 0;
}
