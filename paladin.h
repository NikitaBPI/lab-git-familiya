#pragma once

#include "warrior.h"
#include "wizard.h"

class Paladin : public Warrior, public Wizard
{
public:
    Paladin();
    ~Paladin() override;

    void Create() override;
    void GetInfo() override;
};