#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Array of Animals (Dogs & Cats) ===" << std::endl;
    {
        const int size = 4;
        const Animal* animals[size];

        for (int i = 0; i < size; i++)
        {
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        std::cout << std::endl << "--- makeSound() from array ---" << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << "animals[" << i << "] type: " << animals[i]->getType() << " -> ";
            animals[i]->makeSound();
        }

        std::cout << std::endl << "--- deleting array ---" << std::endl;
        for (int i = 0; i < size; i++)
            delete animals[i];
    }

    std::cout << std::endl;
    std::cout << "=== Copy tests (Dog & Cat) ===" << std::endl;
    {
        std::cout << "--- Dog copy ---" << std::endl;
        Dog d1;
        Dog d2(d1);
        Dog d3;
        d3 = d1;

        std::cout << std::endl;
        std::cout << "--- Cat copy ---" << std::endl;
        Cat c1;
        Cat c2(c1);
        Cat c3;
        c3 = c1;        
    }

    std::cout << std::endl;
    std::cout << "=== End of tests ===" << std::endl;
    return 0;
}
