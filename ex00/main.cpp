#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Correct Polymorphism ===" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    std::cout << "\n=== Wrong Polymorphism ===" << std::endl;

    const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* b = new WrongCat();

    std::cout << a->getType() << std::endl;
    std::cout << b->getType() << std::endl;

    a->makeSound();
    b->makeSound();

    delete a;
    delete b;

    return 0;
}
