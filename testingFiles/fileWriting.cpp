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
#include "Hero.h"
#include "Warrior.h"
#include "Tile.h"
#include "City.h"
#include "Game.h"
using namespace std;

// testing file writing


int main(){
    srand(time(NULL)); 
    cout << "Game class testing:" << endl;
    Game newGame = Game();

    newGame.readTiles("mapGOT.txt", 25);
    newGame.readWarriors("warriorsGOT.txt", 14);
    newGame.readHeroes("heroesGOT2.txt", 6);
    newGame.readCities("citiesGOT.txt", 26);
    newGame.placeDragonglass();
    newGame.placeBoundWarriors();
    newGame.placeFreeWarriors();
    newGame.showWholeMap();
    newGame.printWarriorsStats();
    newGame.setPlayerHeroIndex(0);

    newGame.writeGameStats("resultsGOT.txt");
    return 0;
}