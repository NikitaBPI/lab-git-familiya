#pragma once

#include <memory>
#include "NPC.h"
#include "playerclass.h"

std::unique_ptr<NPC> CreateCharacter(PlayerClass pClass);