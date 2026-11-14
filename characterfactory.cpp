#include "characterfactory.h"
#include "warrior.h"
#include "wizard.h"
#include "paladin.h"

std::unique_ptr<NPC> CreateCharacter(PlayerClass pClass)
{
    switch (pClass)
    {
        case PlayerClass::warrior:
            return std::make_unique<Warrior>();
        case PlayerClass::wizard:
            return std::make_unique<Wizard>();
        case PlayerClass::paladin:
            return std::make_unique<Paladin>();
        default:
            return nullptr;
    }
}