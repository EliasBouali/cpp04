#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Array of AAnimals (Dogs & Cats) ===" << std::endl;
    {
        const int size = 4;
        const AAnimal* animals[size];
        //AAnimal test;
        //AAnimal* test_2 = new AAnimal();


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
    std::cout << "=== End of ex02 tests ===" << std::endl;
    return 0;
}
