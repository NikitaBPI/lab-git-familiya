#pragma once

#include "NPC.h"
#include <string>

class Evil : public NPC
{
public:
    Evil();
    Evil(std::string name);
    Evil(std::string name, unsigned int damage);
    Evil(std::string name, unsigned int damage, unsigned int health);
    Evil(std::string name, unsigned int damage, unsigned int health, unsigned int armor);
    ~Evil() override;
};