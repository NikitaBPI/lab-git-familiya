#pragma once

#include "NPC.h"
#include <memory>

class Player
{
private:
    std::unique_ptr<NPC> currentCharecter{nullptr};

public:
    void Create(std::unique_ptr<NPC> character);
    NPC* GetCharacter();
    void GetInfo();
};