// DangerousEncounters.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <windows.h>
#include "Creature.h"
#include "Monster.h"
#include "Armament.h"
#include "Consumable.h"
#include "ItemRarity.h"
#include "Inventory.h"
#include "Enemy.h"
#include "EnemyType.h"

void StartDuel(Creature& firstCreature, Creature& secondCreature);

int main()
{
    std::cout << "Hello World!\n";
    std::cout << std::endl;
    srand(time(0));
 
    {
        //Attack atkCoupDePoing = Attack("Coup de poing", 2);

        //Creature creatureGontrand = Creature("Gontrand", 40, 3);
        //creatureGontrand.LearnAttack(Attack("Coup de pied", 4));
        //creatureGontrand.LearnAttack(Attack("Coup de tete", 10));

        //Creature creatureEustass = Creature("Eustass", 30, 4);
        //creatureEustass.LearnAttack(atkCoupDePoing);

        //creatureGontrand.AttackTarget(1, creatureEustass);
        //creatureEustass.Heal(4);

        //std::cout << " " << std::endl;
        //std::cout << "     ==========================================\n";
        //std::cout << " " << std::endl;

        //Monster monsterJack = Monster("Jack", 30, 3);
        //std::cout << monsterJack.GetName();

        //creatureEustass.LearnAttack(Attack("/kill", 9999));
        //creatureEustass.AttackTarget(1, monsterJack);

        //std::cout << " " << std::endl;
        //std::cout << "     ==========================================\n";
        //std::cout << " " << std::endl;

        //Creature crtTulipe = Creature("Tulipe", 40, 2);
        //Creature crtRose = Creature("Rose", 34, 6);
        //Monster monsterRocher = Monster("Rocher", 30, 3);

        //Attack atkKick = Attack("Kick", 2);
        //Attack atkPunch = Attack("Punch", 1);
        //
        //crtTulipe.LearnAttack(atkKick);
        //crtRose.LearnAttack(atkPunch);
        //monsterRocher.LearnAttack(atkKick);

        ////crtTulipe.AttackTarget(0, monsterRocher);

        //StartDuel(crtTulipe, monsterRocher); //Fight thing
    }

    /*
    //Create a item class
    //Create inventory class -> vector of item
    //Iterate through the iventory to remove an item that the player chooses
    
    Armament ironSword = Armament("Iron Sword", "An heavy sword made out of iron", ItemRarity::COMMON);
    Armament godlikeSpear = Armament("Spear of the Gods", "A gigantic spear said to have been used by the very gods", ItemRarity::LEGENDARY);
    Consumable switnessPot = Consumable("Potion of swiftness", "Drink to make your character run twice as fast", ItemRarity::RARE);
    Consumable kysPot = Consumable("Throwing potion of instant death", "Throw it at someone and they basically die", ItemRarity::EPIC);

    Armament* ptr = nullptr;
    ptr = &ironSword;


    ironSword.GiveAFullDescription();
    std::cout << std::endl;
    switnessPot.GiveAFullDescription();
    std::cout << std::endl;

    std::vector<Armament> vectorOfItems;
    vectorOfItems.push_back(ironSword);
    vectorOfItems.push_back(godlikeSpear);
    vectorOfItems.push_back(Armament("Wooden Sword"));
    vectorOfItems.push_back(Armament("Gun"));
    vectorOfItems.push_back(Armament("Classic Spear"));
    vectorOfItems.push_back(Armament("Axe"));

    Inventory testInv = Inventory("Test Inventory", vectorOfItems);
    Inventory testInv2 = Inventory("secondInventory", vectorOfItems);

    int waitTime = 1000;

    testInv.Summarise();
    Sleep(waitTime);
    testInv.RemoveObjectAtLocation(4);
    Sleep(waitTime);
    testInv.Summarise();
    Sleep(waitTime);
    testInv.SwapObjects(0, 4);
    Sleep(waitTime);
    testInv.Summarise();
    Sleep(waitTime);
    testInv2.Summarise();
    Sleep(waitTime);
    testInv.GiveItem(0, &testInv2);
    Sleep(waitTime);
    testInv.Summarise();
    Sleep(waitTime);
    testInv2.Summarise();*/

    /*
    Create enum EnemyType
    Create class Enemy
    Enemy can :
        Display its name and types
        Compare his types to an other enemy
        Change type
    */

    Enemy gregoire = Enemy("Gregoire, le fleau des astres");
    gregoire.AddType((uint16_t)EnemyType::Astral);
    gregoire.AddType((uint16_t)EnemyType::Dragon);
    gregoire.DisplayTypes();

    Enemy jacques = Enemy("Jacques, l'intermittent du spectacle");
    jacques.AddType((uint16_t)EnemyType::Shimerscale);
    jacques.DisplayTypes();

    std::cout << jacques.GetName() << " and " << gregoire.GetName() << " have at least 1 type in common : " << jacques.HasTypeInCommon(&gregoire) << std::endl;

    jacques.AddType((uint16_t)EnemyType::Astral);
    jacques.DisplayTypes();

    std::cout << jacques.GetName() << " and " << gregoire.GetName() << " have at least 1 type in common : " << jacques.HasTypeInCommon(&gregoire) << std::endl;

    {//string S = "Ceci est un test";

    //// Traverse the given string S
    //for (int i = 0; i < S[i]; i++) {

    //    cout << S[i];

    //    // Waits for 200 milliseconds
    //    Sleep(200);
    //}

    //return 0;
    }
}

void StartDuel(Creature& firstCreature, Creature& secondCreature) 
{
    Creature& attacker = firstCreature;
    Creature& defender = secondCreature;
    Creature& jonctionSwap = firstCreature;

    int atkSelected;
    int order;
    int round = 0;

    while (firstCreature.GetLifePoint() > 0 || secondCreature.GetLifePoint() > 0) 
    {
        round++;
        std::cout << " " << std::endl;
        std::cout << "   ===== Round " << round << " =====" << std::endl;
        std::cout << " " << std::endl;
        
        order = rand() % 1;
        if (order == true) 
        {
            attacker = firstCreature;
            defender = secondCreature;
        }
        else 
        {
            attacker = secondCreature;
            defender = firstCreature;
        }

        std::cout << attacker.GetName() << " starts the turn\n";
        std::cout << " " << std::endl;
        
        for (size_t j = 0; j < 2; j++)
        {
            std::cout << attacker.GetName() << " has " << attacker.GetAttackPool().size() << " attacks\n";

            for (size_t i = 0; i < attacker.GetAttackPool().size(); i++)
            {
                std::cout << i+1 << ": " << attacker.GetAttackPool()[i].GetName() << std::endl;
            }

            do 
            {
                std::cout << "Choose an attack\n";
                std::cin >> atkSelected;
            } while (atkSelected > attacker.GetAttackPool().size() || atkSelected < 1);
        
            attacker.AttackTarget(atkSelected-1, defender);

            std::cout << defender.GetName() << "'s turn\n";

            if (defender.GetLifePoint() > 0) break;

            jonctionSwap = attacker;
            attacker = defender;
            defender = jonctionSwap;
        }
    }
}