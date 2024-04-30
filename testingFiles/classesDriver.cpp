// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "../Hero.h"
#include "../Warrior.h"
#include "../Tile.h"
#include "../Game.h"
#include "../City.h"
using namespace std;

// basically a getter/setter driver for Hero/Warrior/Tile/City

int main(){
    
    Hero heroes[7];
    Warrior warriors[14];
    warriors[0] = Warrior("Irisviel", 20, 20, 20, false, false, false, 1, 1);
    warriors[1] = Warrior("Maiya", 40, 100, 50, false, true, true, 3, 3);
    warriors[2] = Warrior("Arturia", 100, 80, 80, true, false, true, 3, 4);


    cout << "Testing Hero Class" << endl;
    // overloaded constructor test
    Hero Emiya = Hero("Emiya Kiritsugu", 8000, 0, 10, 0, 1, 2, -1, 0, 0, false);
    Emiya.printAllStats();

    // default constructor tests
    Hero Kotomine = Hero();
    Kotomine.printAllStats(); // should all be empty or garbage

    Kotomine.setName("Kotomine Kirei");
    Kotomine.setMoney(4000);
    Kotomine.setInfluence(20);
    Kotomine.setArmySize(10);
    Kotomine.setW1(3);
    Kotomine.setW2(-1);
    Kotomine.setW3(-1);
    Kotomine.setW4(-1);
    Kotomine.setR(4);
    Kotomine.setC(4);
    Kotomine.setShip(false);
    Kotomine.printAllStats(); // should be filled in


    cout << "Testing Warrior Class" << endl;
    // overloaded constructor test
    Warrior Arturia = Warrior("Arturia", 100, 200, 100, false, false, false, 1, 1);
    Arturia.printAllStats();

    // default constructor tests
    Warrior Maiya = Warrior();
    Maiya.printAllStats(); // should all be empty or garbage

    Maiya.setName("Maiya");
    Maiya.setStrength(40);
    Maiya.setLoyalty(200);
    Maiya.setMorale(200);
    Maiya.setFree(false);
    Maiya.setShip(false);
    Maiya.setHasDragonglass(false);
    Maiya.setR(1);
    Maiya.setC(1);
    Maiya.printAllStats(); // should be filled in


    cout << "Testing Tile Class" << endl;
    // overloaded constructor test
    Tile Tile1 = Tile("Water", false, 0, 3, 3);
    Tile1.printAllStats();
    

    // default constructor tests
    Tile Tile2 = Tile();
    Tile2.printAllStats(); // should all be empty or garbage

    Tile2.setAttribute("Land");
    Tile2.setHasDragonglass(true);
    Tile2.setCityIndex(2);
    Tile2.setR(2);
    Tile2.setC(2);
    Tile2.printAllStats(); // should be filled in


// Making a map:
    //array variables
    int mapRows = 25;
    int mapColumns = 16;
    Tile map[mapRows][mapColumns];

    cout << "Game class testing:" << endl;
    Game newGame = Game();

    cout << "Player view map:" << endl;
    newGame.showPlayerMap();

    cout << "Whole map:" << endl;
    newGame.showWholeMap();
    return 0;
}