#include "player.h"
#include <utility>

using namespace std;

void Player::Create(unique_ptr<NPC> character)
{
    currentCharecter = move(character);
    currentCharecter->Create();
}

NPC* Player::GetCharacter()
{
    return currentCharecter.get();
}

void Player::GetInfo()
{
    if (currentCharecter)
    {
        currentCharecter->GetInfo();
    }
}
