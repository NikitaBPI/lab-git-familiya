#pragma once

#include <string>
#include "weaponquality.h"

struct Weapon
{
    std::string name{"weapon"};
    unsigned int damage{1};
    WeaponQuality  quality{WeaponQuality::none};
};