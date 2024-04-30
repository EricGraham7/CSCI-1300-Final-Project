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

int main(){
    srand(time(NULL)); 
    Game newGame = Game();

//setting everything up
    newGame.readTiles("mapGOT.txt", 25);
    newGame.readWarriors("warriorsGOT.txt", 14);
    newGame.readHeroes("heroesGOT.txt", 6);
    newGame.readCities("citiesGOT.txt", 26);
    newGame.placeDragonglass();
    newGame.placeBoundWarriors();
    newGame.placeFreeWarriors();
    newGame.showWholeMap();
    bool userInput = true;
    int userHeroSelection = -1;
    cout << "1: " << newGame.getHeroName(0)  << ", 2: " << newGame.getHeroName(1)  << ", 3: " << newGame.getHeroName(2)  << ", 4: " << newGame.getHeroName(3)  << ", 5: " << newGame.getHeroName(4) << ", 6: " << newGame.getHeroName(5) << endl;
    userHeroSelection = newGame.inputValidationInt("Please enter the index of the hero you would like to be: ", 1, 6);
    newGame.setPlayerHeroIndex(userHeroSelection-1);

//playing the game
    cout << "The 7x7 map shown every round shows the tiles around your player; the very center is you. " << endl;
    cout << "You can choose to move around, stay in the same place in order to increase your warriors' stats " << endl; 
    cout << "(resting increases strength and consulting increases morale) or view your warriors stats, or reorder them." << endl;
    cout << "The goal of the game is to obtain as much dragonglass as possible, while staying alive." << endl;
    cout << "Once specific conditions are met, the boss will show up, and dragonglass will help you beat them." << endl;
    cout << "You never know what land tiles have dragonglass, or if another hero picked it up, so make sure to battle some other heroes and win some!" << endl;
    newGame.moveEveryone();


    return 0;
}