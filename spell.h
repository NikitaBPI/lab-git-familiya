#pragma once

#include <string>
#include "weaponquality.h"
struct Spell
{
    std::string name{"spell"};
    unsigned int damage{1};
    WeaponQuality quality{WeaponQuality::none};
};