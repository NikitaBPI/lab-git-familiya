#pragma once

#include "NPC.h"
#include "spell.h"
#include <vector>
#include <string>

class Wizard : virtual public NPC
{
protected:
    short intellect{29};
    std::vector<Spell> spells;

public:
    Wizard();
    Wizard(std::string name, unsigned int lvl = 1);
    ~Wizard() override;

    void Create() override;
    void GetInfo() override;
    Spell& LearnSpell();
    void Recalculate();
};