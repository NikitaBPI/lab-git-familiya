#include "paladin.h"
#include <iostream>

using namespace std;

Paladin::Paladin()
{
    intellect = 25;
    strenght = 19;
    health = 25;
    damage = 25;
}

Paladin::~Paladin()
{
    cout << "Отправляется к праотцам" << endl;
}

void Paladin::Create()
{
    cout << "Вы создали Паладина\nЗадайте имя игрока\n";
    cin >> name;

    LearnSpell();
    GetWeapon();
}

void Paladin::GetInfo()
{
    NPC::GetInfo();
    cout << "Сила: " << strenght << endl;
    cout << "Интеллект: " << intellect << endl;
}