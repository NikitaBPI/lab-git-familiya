#include "evil.h"
#include <iostream>

using namespace std;

Evil::Evil()
{
    name = "Злодей";
    health = 10;
    damage = 5;
    armor = 3;
}

Evil::Evil(string name) : Evil()
{
    this->name = name;
}

Evil::Evil(string name, unsigned int damage) : Evil(name)
{
    this->damage = damage;
}

Evil::Evil(string name, unsigned int damage, unsigned int health) : Evil(name, damage)
{
    this->health = health;
}

Evil::Evil(string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
{
    this->armor = armor;
}

Evil::~Evil()
{
    cout << name << " сгинул в пучине адского пламени" << endl;
}