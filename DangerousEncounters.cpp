// DangerousEncounters.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Creature.h"
#include "Monster.h"
#include "Armament.h"
#include "Consumable.h"
#include "ItemRarity.h"
#include "Inventory.h"

void StartDuel(Creature& firstCreature, Creature& secondCreature);

int main()
{
    std::cout << "Hello World!\n";
    std::cout << std::endl;
    srand(time(0));
 
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

    testInv.Summarise();
    testInv.RemoveObjectAtLocation(4);
    testInv.Summarise();
    testInv.SwapObjects(0, 4);
    testInv.Summarise();

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