#include "wizard.h"
#include <iostream>

using namespace std;

Wizard::Wizard()
{
    damage = 27;
    health = 21;
    armor = 10;
}

Wizard::Wizard(string name, unsigned int lvl)
{
    this->name = name;
    for (size_t i = 0; i < lvl - 1; i++)
    {
        LvlUp();
    }
    this->lvl = lvl;
}

Wizard::~Wizard()
{
    cout << name << " испускает дух" << endl;
}

void Wizard::Create()
{
    cout << "Вы создали Мага\nЗадайте имя игрока\n";
    cin >> name;

    LearnSpell();
}

void Wizard::GetInfo()
{
    NPC::GetInfo();
    cout << "Интеллект: " << intellect << endl;
}

Spell& Wizard::LearnSpell()
{
    if (spells.empty())
    {
        Spell spell;
        spell.damage = 1;
        spell.name = "Вспышка";
        spells.push_back(spell);

        cout << name << " Изучил заклинение " << spells.back().name << endl;
        cout << "Добавка к урона = " << spells.back().damage << endl;
    }

    return spells.back();
}

void Wizard::Recalculate()
{
    damage += (1 + lvl * intellect * 0.1);
    health += (1 + lvl * intellect * 0.1);
    armor += (1 + lvl * intellect * 0.1);
}