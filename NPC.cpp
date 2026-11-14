#include "NPC.h"
#include <iostream>

using namespace std;

unsigned int NPC::GetDamage()
{
    return damage;
}

unsigned int NPC::GetHealth()
{
    return health;
}

void NPC::SetHealth(unsigned int health)
{
    this->health = health;
}

void NPC::GetInfo()
{
    cout << "Имя: " << name << endl;
    cout << "Здоровье: " << health << endl;
    cout << "Урон: " << damage << endl;
    cout << "Уровень: " << lvl << endl;
    cout << "Броня: " << armor << endl;
}

void NPC::Create()
{
}

void NPC::LvlUp()
{
    lvl += 1;
    cout << name << " повысил уровень персонажа " << endl;
    Recalculate();
}

void NPC::Recalculate()
{
    damage += (1 + lvl * 0.1);
    health += (1 + lvl * 0.1);
    armor += (1 + lvl * 0.1);
}

void TakeDamage(NPC* npc, unsigned int damage)
{
    npc->SetHealth(npc->GetHealth() - damage);
    cout << npc->name << " получил урон " << damage << endl;
    cout << "Оставшееся здоровье =" << npc->GetHealth() << endl;
}