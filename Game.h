// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - Game class

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include "Warrior.h"
#include "Hero.h"
#include "Tile.h"
#include "City.h"
using namespace std;

class Game
{
    public:
    //constructor, getters, setters
        Game();
        void setPlayerHeroIndex(int inputIndex);
        int getPlayerHeroIndex();
        string getHeroName(int index);
        //glorified setters
        void rest();
        void consult();

    //initializing functions
        void placeDragonglass();
        void placeBoundWarriors();
        void placeFreeWarriors();

    //helper/misc functions
        int findWarrior(string warriorName);
        int findTurnDistance(int hero1, int hero2);
        bool getHeroPossessesShip(int heroIndex); // necessary because the getter for hero class doesn't tell if the hero has a warrior that has a ship
        int checkForCharacterAtLocation(int rIn, int cIn); // return 1 is hero, 2 is warrior
        string convertToLower(string stringToConvert);
        string capitalize(string stringToCapitalize);
        int inputValidationInt(string message, int rangeFloor, int rangeCeiling);
        char inputValidationChar(string message, char option1, char option2, char option3, char option4);
        void reorderWarriors(); // user-only function
    
    //obtaining resources/warriors
        void obtainNewWarriors(int winningHeroIndex, int losingHeroIndex);
        void playerObtainWarrior(int warriorIndex);
        void aiObtainWarrior(int heroIndex, int warriorIndex);
        void freeWarriorFindDragonglass(int warriorIndex);
        void getTileResources(int heroIndex);
            void obtainDragonglass(int heroIndex);

    //moving related
        bool verifyMoveHero(int heroIndex, int tileRow, int tileColumn);
        int moveHero(int heroIndex);
            void moveHerosWarriors(int heroIndex, char direction, int distance);
        bool verifyMoveFreeWarrior(int warriorIndex, int tileRow, int tileColumn);
        int moveFreeWarrior(int warriorIndex);


    //printing info
        void viewWarriorStats(int heroIndex); // for all gameplay purposes, heroIndex here will be playerHeroIndex, but for testing it may be different
        void printHeroesStats();
        void printWarriorsStats();
        void listWarriors(int heroIndex);
        void printWarriorsPositions();
        void printCitiesStats();
        void checkDragonglass();
        void showWholeMap();
        void showPlayerMap();

    // battle-related
        int checkProximity(int heroInQeustion);
            bool inProximity(int hero1, int hero2);
        int checkFreeWarriorProximity(int heroInQuestion);
            bool inFreeWarriorProximity(int hero, int warrior);

        int engage(int engagingHero, int defendingHero);
            //functions used in engage
            int battle(int engagingHero, int defendingHero);
            int buyArmy(int engagingHero, int defendingHero);
            int speech(int engagingHero, int defendingHero);
                int acquireAssets(int winningHero, int losingHero, double factor, bool getAllWarriors);
                void removeHero(int heroIndex);

    // boss-related
        double calculatePowerScore();
        int fightWhiteWalkers();

    // basically the biggest function that puts all the gameplay functions together
        void moveEveryone();

        void endGame(string winOrLose);

    //file io
        //input
            int readHeroes(string fileName, int heroesArraySize);
            int readWarriors(string fileName, int warriorArraySize);
            int readTiles(string fileName, int tilesArraySize);
            int readCities(string fileName, int citiesArraySize);
            void assignCityPositions(int cityIndex);
        //output
            int writeGameStats(string fileName);
            
    private:
    // arrays of the classes
        static const int warriorsSize = 14;
        Warrior warriors[warriorsSize];

        int heroesSize = 6;
        Hero heroes[7];
        
        static const int tilesRows = 25;
        static const int tilesColumns = 16;
        Tile tiles[tilesRows][tilesColumns];

        static const int citiesSize = 26;
        City cities[citiesSize];

    // non-class variables
        int turns;
        int playerHeroIndex;
        bool gameEnd;

        //Hero player = Hero("Player", 200, 200, 200, -1, -1, -1, -1, 0, 0, false); // for testing
};

#endif