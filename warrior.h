#pragma once

#include "NPC.h"
#include "weapon.h"
#include <vector>
#include <string>

class Warrior : virtual public NPC
{
protected:
    short strenght{21};
    std::vector<Weapon> weapons;

public:
    Warrior();
    Warrior(std::string name, unsigned int lvl = 1);
    ~Warrior() override;

    void Create() override;
    void GetInfo() override;
    Weapon& GetWeapon();
    void Recalculate();
};