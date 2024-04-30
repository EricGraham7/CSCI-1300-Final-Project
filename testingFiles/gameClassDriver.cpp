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

// this is where I tested many of the functions

int main(){
    srand(time(NULL)); 
    cout << "Game class testing:" << endl;
    Game newGame = Game();

//testing map
    // cout << "Player view map setup:" << endl;
    // newGame.showPlayerMap();

    // cout << endl;
    // cout << endl;
    // cout << "Whole map setup:" << endl;
    // newGame.showWholeMap();

//testing file reading
    // cout << endl;
    // cout << endl;
    // cout << "Reading tiles: " << endl;
    newGame.readTiles("mapGOT.txt", 25);
    
    // cout << endl;
    // cout << endl;
    // cout << "Whole map after reading:" << endl;
    // newGame.showWholeMap();

    // cout << endl;
    // cout << endl;
    // cout << "Player view map setup:" << endl;
    //newGame.showPlayerMap();
    
    // cout << endl;
    // cout << endl;
    // cout << "Reading warriors: " << endl;
    newGame.readWarriors("warriorsGOT.txt", 14);
    //newGame.printWarriorsStats();

    // cout << endl;
    // cout << endl;
    // cout << "Reading heroes: " << endl;
    newGame.readHeroes("heroesGOT2.txt", 6);
    //newGame.printHeroesStats();
    
    // cout << endl;
    // cout << endl;
    // cout << "Reading cities: " << endl;
    newGame.readCities("citiesGOT.txt", 26);
    //newGame.printCitiesStats();

//testing initializing functions
    newGame.placeDragonglass();
    // cout << endl;
    // cout << endl;
    // cout << "Whole map after placing dragonglass:" << endl;
    // newGame.checkDragonglass();

    // cout << endl;
    // cout << endl;
    // cout << "Placing bound warriors: " << endl;
    newGame.placeBoundWarriors();

    // cout << endl;
    // cout << endl;
    // cout << "Placing free warriors: " << endl;
    newGame.placeFreeWarriors();

    // cout << endl;
    // cout << endl;
    // cout << "Printing warrior stats: " << endl;
    // newGame.printWarriorsStats();
    
    // cout << endl;
    // cout << endl;
    // newGame.showWholeMap();

    newGame.setPlayerHeroIndex(0); // by doing this, I can make sure to test the user versions
                                   // and NPC versions of applicable functions
//testing moving functions
        // testing multiple times to make sure there aren't any patterns
    newGame.moveHero(0);
    newGame.moveHero(0);
    newGame.moveHero(0);
    newGame.moveHero(0);

    newGame.moveHero(1);
    newGame.moveHero(1);
    newGame.moveHero(1);
    newGame.moveHero(1);
    newGame.moveHero(1);
    newGame.moveHero(1);

    newGame.moveFreeWarrior(0);
    newGame.moveFreeWarrior(0);
    newGame.moveFreeWarrior(0);
    newGame.moveFreeWarrior(0);

    newGame.moveFreeWarrior(1);
    newGame.moveFreeWarrior(1);
    newGame.moveFreeWarrior(1);
    newGame.moveFreeWarrior(1);


//testing interaction functions

    // cout << "Testing convertToLower:" << endl;
    // cout << newGame.convertToLower("TESTING") << endl;
    // cout << newGame.convertToLower("") << endl;

    // cout << "Testing findTurnDistance:" << endl;
    // cout << newGame.findTurnDistance(0,1) << endl; // between Cersei at 16,7 and Stannis at 14,9: should be 4
    // cout << newGame.findTurnDistance(0,5) << endl; // between Cersei at 16,7 and Daenerys at 18,16: should be 11
    
    // cout << "Testing inProximity:" << endl;
    // cout << newGame.inProximity(0,1) << endl; // checking proximity of Cersei at 16,7 and Stannis is at 14,9. Should be true (1)
    // cout << newGame.inProximity(0,5) << endl; // checking proximity of Cersei at 16,7 and Daenerys at 18,16. Should be false (0)
    
    // cout << "Testing checkProximity:" << endl;
    // cout << newGame.checkProximity(0) << endl; // checking proximity of Cersei at 16,7 and all others. Since Stannis is at 14,9 should be 1 (Stannis' index)
    // cout << newGame.checkProximity(5) << endl; // checking proximity of Daenerys at 18,16 and all others. Should be -1 for no proximity
    // cout << newGame.checkProximity(0) << endl; // checking proximity of Cersei at 16,7 again, but since Cersei is now immune, should be -1.

//testing engage 
    // cout << "Testing engage:" << endl;

    // newGame.viewWarriorStats(0);

    // newGame.engage(0,1);

    //newGame.viewWarriorStats(0); // if main hero lost, should print 2 heroes, if won, print 4

    //newGame.viewWarriorStats(1); // if main hero lost, shuld print 2 heroes, if main hero won, print 0
    
    // newGame.engage(1,2);

    //     newGame.engage(0,1);
    // newGame.engage(1,2);
    //     newGame.engage(0,1);
    // newGame.engage(1,2);
    
    //newGame.viewWarriorStats(1); // if hero lost, shuld print 0 heroes, if hero won, print 4
    // no need to test buy and speech?


    // newGame.printWarriorsPositions();
    

//testing removeHero
    // cout << "Before removing hero at 0:" << endl;
    // cout << "Before removing hero at 0:" << endl;
    // newGame.printHeroesStats();

    // newGame.removeHero(0);
    
    // cout << "After removing hero at 0:" << endl;
    // cout << "After removing hero at 0:" << endl;
    // newGame.printHeroesStats();


//testing setskin using checkDragnglass as example
    // newGame.checkDragonglass();
    // newGame.setSkin(0);
    // newGame.checkDragonglass();


    return 0;
}