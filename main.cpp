#include <iostream>
#include <memory>
#include <typeinfo>
#include <cstdlib>
#include "player.h"
#include "playerclass.h"
#include "weaponquality.h"
#include "gamestate.h"
#include "characterfactory.h"
#include "warrior.h"
#include "wizard.h"
#include "paladin.h"

using namespace std;

void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void WaitEnter()
{
    cout << "\nНажмите Enter, чтобы продолжить...";
    cin.ignore(10000, '\n');
    cin.get();
}

int main()
{
    Player player;
    GameState currentState = GameState::MainMenu;

    while (currentState != GameState::Exit)
    {
        switch (currentState)
        {
            case GameState::MainMenu:
            {
                ClearScreen();
                cout << "================ Главное Меню ================" << endl;
                cout << "1 - Создать героя" << endl;
                cout << "2 - Сюжет" << endl;
                cout << "3 - Характеристики персонажа" << endl;
                cout << "4 - Выход" << endl;
                cout << "==============================================" << endl;
                cout << "Выберите действие: ";

                short menuChoice = 0;
                if (!(cin >> menuChoice))
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    ClearScreen();
                    cout << "Некорректный ввод! Введите число от 1 до 4." << endl;
                    WaitEnter();
                    break;
                }

                switch (menuChoice)
                {
                    case 1:
                        currentState = GameState::CharacterCreation;
                        break;
                    case 2:
                        currentState = GameState::Story;
                        break;
                    case 3:
                        currentState = GameState::CharacterInfo;
                        break;
                    case 4:
                        currentState = GameState::Exit;
                        break;
                    default:
                        ClearScreen();
                        cout << "Неверный пункт меню! Выберите число от 1 до 4." << endl;
                        WaitEnter();
                        break;
                }
                break;
            }

            case GameState::CharacterCreation:
            {
                ClearScreen();
                cout << "================ Создание Героя ================" << endl;
                cout << "Присядь, путник, у костра и расскажи кто ты:" << endl;
                cout << "\t1 - воин\n\t2 - маг\n\t3 - паладин" << endl;
                cout << "Твой выбор: ";

                short choice = 0;
                if (!(cin >> choice))
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    ClearScreen();
                    cout << "Некорректный ввод! Нужно ввести цифру." << endl;
                    WaitEnter();
                    break;
                }

                auto newHero = CreateCharacter(static_cast<PlayerClass>(choice));
                if (!newHero)
                {
                    ClearScreen();
                    cout << "Таких героев еще не было в наших краях!" << endl;
                    WaitEnter();
                    break;
                }

                player.Create(move(newHero));

                cout << "\nТеперь выбери качество оружия/снаряжения для своего героя:" << endl;
                cout << "\t1 - обычное\n\t2 - необычное\n\t3 - редкое\n\t4 - эпическое\n\t5 - легендарное" << endl;
                cout << "Твой выбор: ";

                short weaponChoice = 0;
                if (!(cin >> weaponChoice) || weaponChoice < 1 || weaponChoice > 5)
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nВыбор не распознан, присвоено обычное качество по умолчанию." << endl;
                    weaponChoice = 1;
                }

                NPC* charPtr = player.GetCharacter();
                if (charPtr != nullptr)
                {
                    if (typeid(*charPtr) == typeid(Warrior))
                    {
                        dynamic_cast<Warrior*>(charPtr)->GetWeapon().quality = static_cast<WeaponQuality>(weaponChoice);
                    }
                    else if (typeid(*charPtr) == typeid(Wizard))
                    {
                        dynamic_cast<Wizard*>(charPtr)->LearnSpell().quality = static_cast<WeaponQuality>(weaponChoice);
                    }
                    else if (typeid(*charPtr) == typeid(Paladin))
                    {
                        dynamic_cast<Paladin*>(charPtr)->GetWeapon().quality = static_cast<WeaponQuality>(weaponChoice);
                        dynamic_cast<Paladin*>(charPtr)->LearnSpell().quality = static_cast<WeaponQuality>(weaponChoice);
                    }
                }

                switch (static_cast<WeaponQuality>(weaponChoice))
                {
                    case WeaponQuality::common:
                        cout << "Ты выбрал обычное снаряжение." << endl;
                        break;
                    case WeaponQuality::uncommon:
                        cout << "Ты выбрал необычное снаряжение." << endl;
                        break;
                    case WeaponQuality::rare:
                        cout << "Ты выбрал редкое снаряжение." << endl;
                        break;
                    case WeaponQuality::epic:
                        cout << "Ты выбрал эпическое снаряжение." << endl;
                        break;
                    case WeaponQuality::legendary:
                        cout << "Ты выбрал легендарное снаряжение." << endl;
                        break;
                    default:
                        break;
                }

                cout << "\nГерой успешно создан!" << endl;
                WaitEnter();
                currentState = GameState::MainMenu;
                break;
            }

            case GameState::Story:
            {
                ClearScreen();
                cout << "===================== СЮЖЕТ =====================" << endl;
                if (player.GetCharacter() == nullptr)
                {
                    cout << "Сначала нужно создать героя в главном меню!" << endl;
                }
                else
                {
                    cout << "Путник поднялся с места, поправил экипировку и направился к заброшенным руинам." << endl;
                    cout << "Впереди завывал холодный ветер, предвещая скорую схватку с порождениями тьмы..." << endl;
                }
                cout << "=================================================" << endl;
                WaitEnter();
                currentState = GameState::MainMenu;
                break;
            }

            case GameState::CharacterInfo:
            {
                ClearScreen();
                cout << "================ ХАРАКТЕРИСТИКИ ================" << endl;
                if (player.GetCharacter() == nullptr)
                {
                    cout << "Герой еще не создан! Сначала создайте его через меню." << endl;
                }
                else
                {
                    player.GetInfo();
                }
                cout << "================================================" << endl;
                WaitEnter();
                currentState = GameState::MainMenu;
                break;
            }

            case GameState::Exit:
            {
                break;
            }
        }
    }

    ClearScreen();

    return 0;
}