#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "=== Subject basic tests ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        AMateria* tmp;

        tmp = src->createMateria("ice");
        me->equip(tmp);

        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob); // * shoots an ice bolt at bob *
        me->use(1, *bob); // * heals bob's wounds *

        delete bob;
        delete me;
        delete src;
    }

    std::cout << std::endl;
    std::cout << "=== Extra tests (slots, invalid index, unknown type) ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria* ice  = src->createMateria("ice");
        AMateria* cure = src->createMateria("cure");
        AMateria* unk  = src->createMateria("fire"); // type inconnu → doit être 0

        me->equip(ice);
        me->equip(cure);
        me->equip(unk); // ne fait rien si unk == 0

        Character bob("bob");

        me->use(0, bob);   // ice
        me->use(1, bob);   // cure
        me->use(2, bob);   // slot vide -> rien
        me->use(42, bob);  // index invalide -> rien

        // test unequip : on enlève la materia du slot 0
        me->use(0, bob);   // avant unequip → fonctionne
        me->unequip(0);
        me->use(0, bob);   // après unequip → ne doit plus rien faire

        delete me;
        delete src;
        // attention : les materias unequipped ne sont pas delete ici,
        // dans un vrai projet il faudrait les stocker quelque part ("le sol").
    }

    std::cout << std::endl;
    std::cout << "=== End of ex03 tests ===" << std::endl;
    return 0;
}
