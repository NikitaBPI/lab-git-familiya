#pragma once

#include <string>

class NPC
{
protected:
    std::string name{"npc"};
    unsigned int damage{2};
    unsigned int health{10};
    short lvl = 1;
    unsigned int armor = 5;

private:
    bool isEnemy = true;

public:
    virtual ~NPC() = default;

    unsigned int GetDamage();
    unsigned int GetHealth();
    void SetHealth(unsigned int health);

    virtual void GetInfo();
    virtual void Create();
    void LvlUp();
    void Recalculate();

    friend void TakeDamage(NPC* npc, unsigned int damage);
};

void TakeDamage(NPC* npc, unsigned int damage);