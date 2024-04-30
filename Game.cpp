// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - Game class

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
using namespace std;

Game::Game()
{   
    // Heroes
    for(int i = 0; i < 7; i++)
    {
        heroes[i].setName("");
        heroes[i].setMoney(0);
        heroes[i].setInfluence(0);
        heroes[i].setArmySize(0);
        heroes[i].setW1(-1);
        heroes[i].setW2(-1);
        heroes[i].setW3(-1);
        heroes[i].setW4(-1);
        heroes[i].setR(0);
        heroes[i].setC(0);
        heroes[i].setShip(false);
    }
    // Warriors
    for(int i = 0; i < 14; i++)
    {
        warriors[i].setName("");
        warriors[i].setStrength(0);
        warriors[i].setLoyalty(0);
        warriors[i].setMorale(0);
        warriors[i].setFree(false);
        warriors[i].setShip(false);
        warriors[i].setHasDragonglass(false);
        warriors[i].setR(0);
        warriors[i].setC(0);
    }

    // Tiles
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            tiles[i][j].setAttribute(" "); // 
            tiles[i][j].setHasDragonglass(false);
            tiles[i][j].setR(i);
            tiles[i][j].setC(j);
        }
    } 


    // Cities
    for(int i = 0; i < 7; i++)
    {
        cities[i].setLetter('a');
        cities[i].setName("");
        cities[i].setMoney(0);
        cities[i].setArmySize(0);
        cities[i].setR(0);
        cities[i].setC(0);
    }

    turns = 0;
    playerHeroIndex = -1;
}


                // the few setters and getters:

void Game::setPlayerHeroIndex(int inputIndex){
    playerHeroIndex = inputIndex;
}

int Game::getPlayerHeroIndex(){
    return playerHeroIndex;
}

string Game::getHeroName(int index){
    return heroes[index].getName();
}
void Game::rest(){
    if (heroes[playerHeroIndex].getW1() > -1)
    {
        warriors[heroes[playerHeroIndex].getW1()].setStrength(warriors[heroes[playerHeroIndex].getW1()].getStrength() + 2);
    }
    if (heroes[playerHeroIndex].getW2() > -1)
    {
        warriors[heroes[playerHeroIndex].getW2()].setStrength(warriors[heroes[playerHeroIndex].getW2()].getStrength() + 2);
    }
    if (heroes[playerHeroIndex].getW3() > -1)
    {
        warriors[heroes[playerHeroIndex].getW3()].setStrength(warriors[heroes[playerHeroIndex].getW3()].getStrength() + 2);
    }
    if (heroes[playerHeroIndex].getW4() > -1)
    {
        warriors[heroes[playerHeroIndex].getW4()].setStrength(warriors[heroes[playerHeroIndex].getW4()].getStrength() + 2);
    }
}

void Game::consult(){
    if (heroes[playerHeroIndex].getW1() > -1)
    {
        warriors[heroes[playerHeroIndex].getW1()].setMorale(warriors[heroes[playerHeroIndex].getW1()].getMorale() + 2);
    }
    if (heroes[playerHeroIndex].getW2() > -1)
    {
        warriors[heroes[playerHeroIndex].getW2()].setMorale(warriors[heroes[playerHeroIndex].getW2()].getMorale() + 2);
    }
    if (heroes[playerHeroIndex].getW3() > -1)
    {
        warriors[heroes[playerHeroIndex].getW3()].setMorale(warriors[heroes[playerHeroIndex].getW3()].getMorale() + 2);
    }
    if (heroes[playerHeroIndex].getW4() > -1)
    {
        warriors[heroes[playerHeroIndex].getW4()].setMorale(warriors[heroes[playerHeroIndex].getW4()].getMorale() + 2);
    }
}


                //placing randomized elements on map 

void Game::placeDragonglass(){
     
    int dragonglassPlaced = 0;
    //loop through the tiles array and if it's a land tile with no city and no dragonglass
    //create a random number to decide whether the tile has dragonglass or not
    //if it is, increment the counter for dragonglass placed

    while (dragonglassPlaced < 5)
    {
        for(unsigned int i = 0; i < tilesRows && dragonglassPlaced < 5; i++)
        {
            for(unsigned int j = 0; j < tilesColumns && dragonglassPlaced < 5; j++)
            {
                if (tiles[i][j].getAttribute() == "#" && tiles[i][j].getCityIndex() == -1)
                {
                    if ((rand() % 136) < 5 && tiles[i][j].getHasDragonglass() == false)
                    {
                        //cout << "Placing dragonglass at [" << i << "][" << j << "] " << endl;
                        tiles[i][j].setHasDragonglass(true);
                        dragonglassPlaced++;
                    }
                }
            }
        }
    }
}

void Game::checkDragonglass(){
    for(unsigned int i = 0; i < tilesRows; i++)
    {
        for(unsigned int j = 0; j < tilesColumns; j++)
        {
            if (tiles[i][j].getHasDragonglass())
            {
                cout << "Tile [" << i << "][" << j << "] has dragonglass" << endl;
            }
        }
    }
}

void Game::placeBoundWarriors(){
    for (unsigned int i = 0; i < heroesSize; i++)
    {
        if (heroes[i].getW1() >= 0)
        {
            warriors[heroes[i].getW1()].setR(heroes[i].getR());
            warriors[heroes[i].getW1()].setC(heroes[i].getC());
        }
        if (heroes[i].getW2() >= 0)
        {
            warriors[heroes[i].getW2()].setR(heroes[i].getR());
            warriors[heroes[i].getW2()].setC(heroes[i].getC());
        }
        if (heroes[i].getW3() >= 0)
        {
            warriors[heroes[i].getW3()].setR(heroes[i].getR());
            warriors[heroes[i].getW3()].setC(heroes[i].getC());
        }
        if (heroes[i].getW4() >= 0)
        {
            warriors[heroes[i].getW4()].setR(heroes[i].getR());
            warriors[heroes[i].getW4()].setC(heroes[i].getC());
        }
    }
}

void Game::placeFreeWarriors(){

     
    bool warriorPlaced = false;
    //loop through warriors and if it's a free warrior:
        // if the warrior does have a ship,
            //if the tile is any tile with no hero, no warrior
            //create a random number to decide whether to place the hero there or not.
            //if the warrior is placed, move onto the next warrior
        //loop through the tiles array and if the warrior doesn't have a ship: 
            //if the tile is a land tile with no hero, no warrior
            //create a random number to decide whether to place the hero there or not.
            //if the warrior is placed, move onto the next warrior

    for (unsigned int i = 0; i < warriorsSize; i++)
    {
        warriorPlaced = false;
        if (warriors[i].getFree() == true) // only free warriors won't have been placed
        {
            //cout << "Warrior to be placed: " << warriors[i].getName() << endl;
            while (warriorPlaced == false) // this while loop uses warriorPlaced just in case the random number was never less than 1, we try again until it is
            {
                //cout << "Looping through tiles:" << endl;
                for (unsigned int j = 0; j < tilesRows && warriorPlaced == false; j++)
                {                                                                  //> looping through tiles array
                    for (unsigned int k = 0; k < tilesColumns && warriorPlaced == false; k++)
                    {
                    //cout << "Index: [" << j << "][" << k << "] " << endl;  
                        if (checkForCharacterAtLocation(j, k) < 0) // can't place where there's a hero or warrior already
                        {
                            //cout << "No character here. Attempting to place." << endl;
                            if (warriors[i].getShip() == true && tiles[j][k].getAttribute() == " "/*check this condition; just added*/) // if the warrior has a ship, we can place on any tile
                            {
                                //cout << "Warrior has a ship. Will they get placed here?" << endl;
                                if ((rand() % 400) < 1) // 400 is number of tiles
                                {
                                    //cout << "Placing " << warriors[i].getName() << " at [" << j << "][" << k << "] " << endl;
                                    warriors[i].setR(j);
                                    warriors[i].setC(k);
                                    warriorPlaced = true;
                                }
                            }
                            else if (tiles[j][k].getAttribute() == "#") // if they didn't have a ship, we can only place on land tiles
                            {
                                //cout << "Warrior doesn't have a ship. Will they get placed here?" << endl;
                                if ((rand() % 162) < 1) // 162 is number of land tiles
                                {
                                    //cout << "Placing " << warriors[i].getName() << " at [" << j << "][" << k << "] " << endl;
                                    warriors[i].setR(j);
                                    warriors[i].setC(k);
                                    warriorPlaced = true;
                                }
                            }
                            else {
                                //cout << "Water tile and warrior doesn't have ship" << endl;
                            }
                        
                        }
                        else {
                            //cout << "A character is already here." << endl;
                        }
                    }
                }
            }
        }
    }

}


                //helper functions/printing functions

int Game::checkForCharacterAtLocation(int rIn, int cIn){
    for (unsigned int i = 0; i < heroesSize; i++)
    {
        if (heroes[i].getR() == rIn && heroes[i].getC() == cIn)
        {
            return 1; // hero found
        }
    }
    for (unsigned int i = 0; i < warriorsSize; i++)
    {
        if (warriors[i].getR() == rIn && warriors[i].getC() == cIn)
        {
            return 2; // warrior found
        }
    }
    return -1;
}

int Game::inputValidationInt(string message, int rangeFloor, int rangeCeiling){
    string userInput = "";
    bool isValidInput = false;

    if (message != "")
    {
        cout << message << endl;
    }
    

    while (!isValidInput)
    {
        isValidInput = true;
        getline(cin, userInput);

        // tests to make sure we don't pass an invalid value into stoi below
        if (userInput == "")
        {   // don't want to pass an empty string
            isValidInput = false;
        }
        else 
        {   // don't want to pass any string that has anything other than digits
            for (int i = 0; i < userInput.length(); i++) 
            {
                if (!isdigit(userInput[i]))
                {
                    //cout << "Not able to convert with stoi" << endl;
                    isValidInput = false;
                }
            }
        }

        if (isValidInput == false) // if we need to get a new input, prompt user.
        {
            cout << "Invalid input type or length. Retry." << endl;
        }
        else //the input was the right kind, but not in the range.
        {
            if (stoi(userInput) < rangeFloor || stoi(userInput) > rangeCeiling)
            {
                isValidInput = false;
                cout << "Input is not in the acceptable range. Retry." << endl;
            }
        }
    }
    return stoi(userInput);
}
char Game::inputValidationChar(string message, char option1, char option2, char option3, char option4){
    string userInput = "";
    bool isValidInput = false;

    if (message != "")
    {
        cout << message << endl;
    }

    while (!isValidInput)
    {
        isValidInput = true;
        getline(cin, userInput);

        // tests to make sure we don't pass an invalid value into stoi below
        if (userInput == "" || userInput.length() > 1)
        {   // don't want an empty string or anything longer than 1 character
            isValidInput = false;
        }
        else 
        {   // don't want to pass any string that has anything other than alpha at 0
            if (!isalpha(userInput[0]))
            {
                isValidInput = false;
            }
        }

        if (isValidInput == false) // if we need to get a new input, prompt user.
        {
            cout << "Invalid input. Retry." << endl;
        }
        else //the input was the right kind, but not in the range.
        {
            if ((userInput[0] != option1) && (userInput[0] != option2) && (userInput[0] != option3) && (userInput[0] != option4))
            {
                isValidInput = false;
                cout << "Input is not in the acceptable range. Retry." << endl;
            }
        }
    }
    return userInput[0];
}

bool Game::getHeroPossessesShip(int heroIndex){ //a bit more than a getter, this checks if the hero or any of their warriors has a ship
    if (heroes[heroIndex].getShip() == true)
    {
        return true;
    }
    if (warriors[heroes[heroIndex].getW1()].getShip() == true)
    {
        return true;
    }
    if (warriors[heroes[heroIndex].getW2()].getShip() == true)
    {
        return true;
    }
    if (warriors[heroes[heroIndex].getW3()].getShip() == true)
    {
        return true;
    }
    if (warriors[heroes[heroIndex].getW4()].getShip() == true)
    {
        return true;
    }
    return false;
}

string Game::convertToLower(string stringToConvert){
    string temp = "";
    for (int i = 0; i < stringToConvert.length(); i++)
    {
        temp = temp + char(tolower(stringToConvert[i]));
    }
    return temp;
}

string Game::capitalize(string stringToCapitalize){
    string temp = "";
    temp = temp + char(toupper(stringToCapitalize[0]));
    temp = temp + stringToCapitalize.substr(1, stringToCapitalize.length() - 1);
    return temp;
}

int Game::findWarrior(string warriorName){
    //cout << "Name to match: " << warriorName << "." << endl;
    for(unsigned int i = 0; i < warriorsSize; i++)
    {
        //cout << "Matching to: " << warriors[i].getName() << "." << endl;
        if(warriors[i].getName() == warriorName)
        {
            //cout << "Match! i: " << i << endl;
            return i;
        }
    }
    //cout << "Match fail" << endl;
    return -1;
}

int Game::findTurnDistance(int hero1, int hero2){
    return (abs(heroes[hero1].getR() - heroes[hero2].getR()) + abs(heroes[hero1].getC() - heroes[hero2].getC()));
}

void Game::reorderWarriors(){
    int newWarrior1 = -1;
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    int temp4 = 0;
    int numWarriors = 0;
    bool reorderFinish = false;
    if (heroes[playerHeroIndex].getW1() > -1)
    {
        cout << "Warrior 1: " << warriors[heroes[playerHeroIndex].getW1()].getName() << endl;
        numWarriors++;
        if (heroes[playerHeroIndex].getW2() > -1)
        {
            cout << "Warrior 2: " << warriors[heroes[playerHeroIndex].getW2()].getName() << endl;
            numWarriors++;
            if (heroes[playerHeroIndex].getW3() > -1)
            {
                cout << "Warrior 3: " << warriors[heroes[playerHeroIndex].getW3()].getName() << endl;
                numWarriors++;
                if (heroes[playerHeroIndex].getW4() > -1)
                {
                    cout << "Warrior 4: " << warriors[heroes[playerHeroIndex].getW4()].getName() << endl;
                    numWarriors++;
                }
            }
        }
        else
        {
            cout << "You only have 1 warrior. Unable to reorder." << endl;
            return;
        }
    }
    else
    {
        cout << "You don't have any warriors. Unable to reorder." << endl;
        return;
    }
    cout << "Type which hero you want to move to slot 1" << endl;
    if (numWarriors == 2)
    {
        newWarrior1 = inputValidationInt("", 1, 2); // calling with empty string because message has already been printed.
        if (newWarrior1 == 2)
        {
            temp1 = heroes[playerHeroIndex].getW1();
            temp2 = heroes[playerHeroIndex].getW2();
            heroes[playerHeroIndex].setW1(temp2);
            heroes[playerHeroIndex].setW2(temp1);
        }
        else 
        {
            cout << "No change." << endl;
        }
    }
    else if (numWarriors == 3)
    {
        newWarrior1 = inputValidationInt("", 1, 3); // calling with empty string because message has already been printed.
        temp1 = heroes[playerHeroIndex].getW1();
        temp2 = heroes[playerHeroIndex].getW2();
        temp3 = heroes[playerHeroIndex].getW3();
        if (newWarrior1 == 2)
        {
            heroes[playerHeroIndex].setW1(temp2);
            heroes[playerHeroIndex].setW2(temp1);
            heroes[playerHeroIndex].setW3(temp3);
        }
        else if (newWarrior1 == 3)
        {
            heroes[playerHeroIndex].setW1(temp3);
            heroes[playerHeroIndex].setW2(temp1);
            heroes[playerHeroIndex].setW3(temp2);
        }
        else
        {
            cout << "No change." << endl;
        }
    }
    else if (numWarriors == 4)
    {
        newWarrior1 = inputValidationInt("", 1, 4); // calling with empty string because message has already been printed.
        temp1 = heroes[playerHeroIndex].getW1();
        temp2 = heroes[playerHeroIndex].getW2();
        temp3 = heroes[playerHeroIndex].getW3();
        temp4 = heroes[playerHeroIndex].getW4();
        if (newWarrior1 == 2)
        {
            heroes[playerHeroIndex].setW1(temp2);
            heroes[playerHeroIndex].setW2(temp1);
            heroes[playerHeroIndex].setW3(temp3);
            heroes[playerHeroIndex].setW4(temp4);
        }
        else if (newWarrior1 == 3)
        {
            heroes[playerHeroIndex].setW1(temp3);
            heroes[playerHeroIndex].setW2(temp1);
            heroes[playerHeroIndex].setW3(temp2);
            heroes[playerHeroIndex].setW4(temp4);
        }
        else if (newWarrior1 == 4)
        {
            heroes[playerHeroIndex].setW1(temp4);
            heroes[playerHeroIndex].setW2(temp1);
            heroes[playerHeroIndex].setW3(temp2);
            heroes[playerHeroIndex].setW4(temp3);
        }
        else
        {
            cout << "No change." << endl;
        }
    }
}

                //moving functions and picking up resources/warriors

bool Game::verifyMoveHero(int heroIndex, int tileRow, int tileColumn){
    // cout << "Hero index: " << heroIndex << endl;
    // cout << "R: " << tileRow << endl;
    // cout << "C: " << tileColumn << endl;

    if (tileRow < 0 || tileRow > 24 || tileColumn < 0 || tileColumn > 15) // if the tile doesn't exist
    {
        if (heroIndex == playerHeroIndex)
        {
            cout << "Tile does not exist." << endl;
            // cout << "Please enter a valid direction." << endl;
        }
        return false;
    }
    else {
        if (tiles[tileRow][tileColumn].getAttribute() != " ")
        {
            // cout << "Tile is land. Direction is valid. Moving hero." << endl;
            return true;
        }
        else {
            if (getHeroPossessesShip(heroIndex) == true)
            {
                // cout << "Tile is water but hero has ship. Direction is valid. Moving hero." << endl;
                return true;
            }
            else {
                if (heroIndex == playerHeroIndex)
                {
                    cout << "Tile is water and hero does not have ship. Please enter a valid direction." << endl;
                }
                return false;
                //prompt new move.
            }
        }
    }
    //cout << "Please enter a valid direction." << endl;
    return false;
}

int Game::moveHero(int heroIndex){ // free warrior version won't ask for input, but otherwise the same
     
    int randNum = 0;
    char direction = 'a';
    bool valid = true;
    bool endLoop = false;

    // cout << "Original location of " << heroes[heroIndex].getName() << " is [" << heroes[heroIndex].getR() << "][" << heroes[heroIndex].getC() << "]" << endl;

    while(!endLoop) 
    {
        if (heroIndex == playerHeroIndex)
        {
            direction = inputValidationChar("Choose an option: n, e, s, w", 'n', 'e', 's', 'w');
        }
        else
        {
            randNum = (rand() % 4);
            // cout << "Random number: " << randNum << endl;
            if (randNum == 0)
            {
                direction = 'n';
            }
            else if (randNum == 1)
            {
                direction = 'e';
            }
            else if (randNum == 2)
            {
                direction = 's';
            }
            else 
            {
                direction = 'w';
            }
        }
        //cout << "Direction: " << direction << endl;

        switch (direction)
        {
            case 'n':
            case 'N':
                if (verifyMoveHero(heroIndex, heroes[heroIndex].getR() - 1, heroes[heroIndex].getC()))
                {
                    //cout << "Moving " << direction << endl;
                    heroes[heroIndex].travel('n', 1);
                    moveHerosWarriors(heroIndex, 'n', 1);
                    endLoop = true;
                }
                // else {
                //     cout << "Move " << direction << " failed." << endl;
                // }
                break;
            case 'e':
            case 'E':
                if (verifyMoveHero(heroIndex, heroes[heroIndex].getR(), heroes[heroIndex].getC() + 1))
                {
                    //cout << "Moving " << direction << endl;
                    heroes[heroIndex].travel('e', 1);
                    moveHerosWarriors(heroIndex, 'e', 1);
                    endLoop = true;
                }
                // else {
                //     cout << "Move " << direction << " failed." << endl;
                // }
                break;
            case 's':
            case 'S':
                if (verifyMoveHero(heroIndex, heroes[heroIndex].getR() + 1, heroes[heroIndex].getC()))
                {
                    //cout << "Moving " << direction << endl;
                    heroes[heroIndex].travel('s', 1);
                    moveHerosWarriors(heroIndex, 's', 1);
                    endLoop = true;
                }
                // else {
                //     cout << "Move " << direction << " failed." << endl;
                // }
                break;
            case 'w':
            case 'W':
                if (verifyMoveHero(heroIndex, heroes[heroIndex].getR(), heroes[heroIndex].getC() - 1))
                {
                    //cout << "Moving " << direction << endl;
                    heroes[heroIndex].travel('w', 1);
                    moveHerosWarriors(heroIndex, 'w', 1);
                    endLoop = true;
                }
                // else {
                //     cout << "Move " << direction << " failed." << endl;
                // }
                // break;
            default:
                // cout << "Move failed." << endl;
                break;
        }
    }
    // cout << "New location of " << heroes[heroIndex].getName() << " is [" << heroes[heroIndex].getR() << "][" << heroes[heroIndex].getC() << "]" << endl;
    return 0;
}

void Game::moveHerosWarriors(int heroIndex, char direction, int distance){
    if (heroes[heroIndex].getW1() > -1)
    {
        warriors[heroes[heroIndex].getW1()].travel(direction, distance);
    }
    if (heroes[heroIndex].getW2() > -1)
    {
        warriors[heroes[heroIndex].getW2()].travel(direction, distance);
    }
    if (heroes[heroIndex].getW3() > -1)
    {
        warriors[heroes[heroIndex].getW3()].travel(direction, distance);
    }
    if (heroes[heroIndex].getW4() > -1)
    {
        warriors[heroes[heroIndex].getW4()].travel(direction, distance);
    }
}

bool Game::verifyMoveFreeWarrior(int warriorIndex, int tileRow, int tileColumn){
    // cout << "Warrior index: " << warriorIndex << endl;
    // cout << "R: " << tileRow << endl;
    // cout << "C: " << tileColumn << endl;

    if (tileRow < 0 || tileRow > 24 || tileColumn < 0 || tileColumn > 15) // if the tile doesn't exist
    {
        // cout << "Tile does not exist." << endl;
        return false;
    }
    else {
        if (tiles[tileRow][tileColumn].getAttribute() != " ")
        {
            //cout << "Tile is land. Direction is valid. Moving warrior." << endl;
            return true;
        }
        else {
            if (warriors[warriorIndex].getShip() == true)
            {
                //cout << "Tile is water but warrior has ship. Direction is valid. Moving warrior." << endl;
                return true;
            }
            else {
                //cout << "Tile is water and warrior does not have ship. Please enter a valid direction." << endl;
                return false;
                //prompt new move.
            }
        }
    }
    //cout << "Please enter a valid direction." << endl;
    return false;
}

int Game::moveFreeWarrior(int warriorIndex){
     
    int randNum = 0;
    char direction = 'a';
    bool valid = true;
    bool endLoop = false;

    // cout << "Original location of " << warriors[warriorIndex].getName() << " is [" << warriors[warriorIndex].getR() << "][" << warriors[warriorIndex].getC() << "]" << endl;

    while(!endLoop) 
    {
        randNum = (rand() % 4);
        // cout << "Random number: " << randNum << endl;
        if (randNum == 0)
        {
            direction = 'n';
        }
        else if (randNum == 1)
        {
            direction = 'e';
        }
        else if (randNum == 2)
        {
            direction = 's';
        }
        else 
        {
            direction = 'w';
        }
        //cout << "Direction: " << direction << endl;

        switch (direction)
        {
            case 'n':
            case 'N':
                if (verifyMoveFreeWarrior(warriorIndex, warriors[warriorIndex].getR() - 1, warriors[warriorIndex].getC()))
                {
                    //cout << "Moving " << direction << endl;
                    warriors[warriorIndex].travel('n', 1);
                    endLoop = true;
                }
                // else {
                //     cout << "Move " << direction << " failed." << endl;
                // }
                break;
            case 'e':
            case 'E':
                if (verifyMoveFreeWarrior(warriorIndex, warriors[warriorIndex].getR(), warriors[warriorIndex].getC() + 1))
                {
                    //cout << "Moving " << direction << endl;
                    warriors[warriorIndex].travel('e', 1);
                    endLoop = true;
                }
                // else {
                //     cout << "Move " << direction << " failed." << endl;
                // }
                break;
            case 's':
            case 'S':
                if (verifyMoveFreeWarrior(warriorIndex, warriors[warriorIndex].getR() + 1, warriors[warriorIndex].getC()))
                {
                    //cout << "Moving " << direction << endl;
                    warriors[warriorIndex].travel('s', 1);
                    endLoop = true;
                }
                // else {
                //     cout << "Move " << direction << " failed." << endl;
                // }
                break;
            case 'w':
            case 'W':
                if (verifyMoveFreeWarrior(warriorIndex, warriors[warriorIndex].getR(), warriors[warriorIndex].getC() - 1))
                {
                    //cout << "Moving " << direction << endl;
                    warriors[warriorIndex].travel('w', 1);
                    endLoop = true;
                }
                // else {
                //     cout << "Move " << direction << " failed." << endl;
                // }
                // break;
            default:
                // cout << "Move failed." << endl;
                break;
        }
    }
    // cout << "New location of " << warriors[warriorIndex].getName() << " is [" << warriors[warriorIndex].getR() << "][" << warriors[warriorIndex].getC() << "]" << endl;
    return 0;
}

void Game::obtainDragonglass(int heroIndex){
    
    if (warriors[heroes[heroIndex].getW1()].getHasDragonglass() == false)
    {
        if (heroIndex == playerHeroIndex)
        {
            cout << "Your warrior " << warriors[heroes[heroIndex].getW1()].getName() << " has been equipped with a dragonglass!" << endl;
        }
        warriors[heroes[heroIndex].getW1()].setHasDragonglass(true);
    }
    else if (warriors[heroes[heroIndex].getW2()].getHasDragonglass() == false)
    {
        if (heroIndex == playerHeroIndex)
        {
            cout << "Your warrior " << warriors[heroes[heroIndex].getW2()].getName() << " has been equipped with a dragonglass!" << endl;
        }
        warriors[heroes[heroIndex].getW2()].setHasDragonglass(true);
    }
    else if (warriors[heroes[heroIndex].getW3()].getHasDragonglass() == false)
    {
        if (heroIndex == playerHeroIndex)
        {
            cout << "Your warrior " << warriors[heroes[heroIndex].getW3()].getName() << " has been equipped with a dragonglass!" << endl;
        }
        warriors[heroes[heroIndex].getW3()].setHasDragonglass(true);
    }
    else if (warriors[heroes[heroIndex].getW4()].getHasDragonglass() == false)
    {
        if (heroIndex == playerHeroIndex)
        {
            cout << "Your warrior " << warriors[heroes[heroIndex].getW4()].getName() << " has been equipped with a dragonglass!" << endl;
        }
        warriors[heroes[heroIndex].getW4()].setHasDragonglass(true);
    }
    else 
    {
        if (heroIndex == playerHeroIndex)
        {
            cout << "Your warriors all have a dragonglass already, so you destroy it so no one else can take it." << endl;
        } 
    }
}

void Game::getTileResources(int heroIndex){

    if (tiles[heroes[heroIndex].getR()][heroes[heroIndex].getC()].getHasDragonglass() == true)
    {
        if (heroIndex == playerHeroIndex)
        {
            cout << "You found a dragonglass!" << endl;
        }
        obtainDragonglass(heroIndex);

        tiles[heroes[heroIndex].getR()][heroes[heroIndex].getC()].setHasDragonglass(false);
    }

    if (tiles[heroes[heroIndex].getR()][heroes[heroIndex].getC()].getAttribute() == " ")
    {
        heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + ((rand() % 2 ) * 10));
        heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() + 10);
    }
    else
    {
        for (unsigned int i = 0; i < citiesSize; i++)
        {
            //cities[i].printAllStats();
            if (cities[i].getR() == heroes[heroIndex].getR() && cities[i].getC() == heroes[heroIndex].getC())
            {
                if (cities[i].getBelongsToHero() == heroIndex) // ift the city is already the hero's
                {
                    return;
                }
                //if the hero doesn't have this city,
                heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + cities[i].getArmySize());
                heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() + cities[i].getMoney());
                cities[i].setBelongsToHero(heroIndex);
                return;
            }
        }

        heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + 10);
        heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() + 20);
    }
}

void Game::freeWarriorFindDragonglass(int warriorIndex){
    if (tiles[warriors[warriorIndex].getR()][warriors[warriorIndex].getC()].getHasDragonglass() == true)
    {
        cout << warriors[warriorIndex].getName() << " found a dragonglass!" << endl;
        if (warriors[warriorIndex].getHasDragonglass() == false)
        {
            warriors[warriorIndex].setHasDragonglass(true);
        }
        tiles[warriors[warriorIndex].getR()][warriors[warriorIndex].getC()].setHasDragonglass(false);
    }
}

void Game::obtainNewWarriors(int winningHeroIndex, int losingHeroIndex){

    if (heroes[losingHeroIndex].getW4() > -1) // if the losing hero has a warrior in spot 4
    {
        if (winningHeroIndex == playerHeroIndex)
        {
            playerObtainWarrior(heroes[losingHeroIndex].getW4());
            heroes[losingHeroIndex].setW4(-1);
        }
        else
        {
            aiObtainWarrior(winningHeroIndex, heroes[losingHeroIndex].getW4());
            heroes[losingHeroIndex].setW4(-1);
        }
    }
    else if (heroes[losingHeroIndex].getW3() > -1) // if the losing hero has a warrior in spot 3
    {
        if (winningHeroIndex == playerHeroIndex)
        {
            playerObtainWarrior(heroes[losingHeroIndex].getW3());
            heroes[losingHeroIndex].setW3(-1);
        }
        else
        {
            aiObtainWarrior(winningHeroIndex, heroes[losingHeroIndex].getW3());
            heroes[losingHeroIndex].setW3(-1);
        }
    }
    else if (heroes[losingHeroIndex].getW2() > -1) // if the losing hero has a warrior in spot 2
    {
        if (winningHeroIndex == playerHeroIndex)
        {
            playerObtainWarrior(heroes[losingHeroIndex].getW2());
            heroes[losingHeroIndex].setW2(-1);
        }
        else
        {
            aiObtainWarrior(winningHeroIndex, heroes[losingHeroIndex].getW2());
            heroes[losingHeroIndex].setW2(-1);
        }
    }
    else if (heroes[losingHeroIndex].getW1() > -1) // if the losing hero has a warrior in spot 1
    {
        if (winningHeroIndex == playerHeroIndex)
        {
            playerObtainWarrior(heroes[losingHeroIndex].getW1());
            heroes[losingHeroIndex].setW1(-1);
        }
        else
        {
            aiObtainWarrior(winningHeroIndex, heroes[losingHeroIndex].getW1());
            heroes[losingHeroIndex].setW1(-1);
        }
    }
    else // the losing hero has no warriors
    {
        //testing
        // cout << "Winner (" << heroes[winningHeroIndex].getName() << ") now has these " << warriorDisplayName <<  "s: " << endl;
        // listWarriors(winningHeroIndex);
        removeHero(losingHeroIndex); // if a hero had no warriors was defeated with buyarmy or speech, they're permanently removed
        //or if the hero is defeated with battle, it will be removed

    }
            
    //testing - if the hero was deleted, the net hero in the array will be shown - could cause seg fault!
    // cout << "Winner (" << heroes[winningHeroIndex].getName() << "): " << endl;
    // listWarriors(winningHeroIndex);
    // cout << "Loser (" << heroes[losingHeroIndex].getName() << "): " << endl;
    // listWarriors(losingHeroIndex);
}

void Game::playerObtainWarrior(int warriorIndex){
    string choice = "";
    bool validInput = false;
    bool validInput2 = false;

    if (heroes[playerHeroIndex].getW1() == -1)
    {
        cout << "Congratulations! You have obtained " << warriors[warriorIndex].getName() << "!" << endl;
        heroes[playerHeroIndex].setW1(warriorIndex);
    }
    else if (heroes[playerHeroIndex].getW2() == -1)
    {
        cout << "Congratulations! You have obtained " << warriors[warriorIndex].getName() << "!" << endl;
        heroes[playerHeroIndex].setW2(warriorIndex);
    }
    else if (heroes[playerHeroIndex].getW3() == -1)
    {
        cout << "Congratulations! You have obtained " << warriors[warriorIndex].getName() << "!" << endl;
        heroes[playerHeroIndex].setW3(warriorIndex);
    }
    else if (heroes[playerHeroIndex].getW4() == -1)
    {
        cout << "Congratulations! You have obtained " << warriors[warriorIndex].getName() << "!" << endl;
        heroes[playerHeroIndex].setW4(warriorIndex);
    }
    else // hero has all 4 heroes
    {
        cout << "You have obtained " << warriors[warriorIndex].getName() << ", but you cannot have more than 4 warriors at a time." << endl;
        cout << "Would you like to obtain " << warriors[warriorIndex].getName() << "? (y/n)" << endl;
        warriors[warriorIndex].printUserSideStats();
        // show the stats of the warrior in queston?
        while(!validInput)
        {
            cin >> choice;
            choice = convertToLower(choice);
            if (choice == "yes" || choice == "y")
            {
                cout << endl;
                cout << "Who would you like to release in order to obtain " << warriors[warriorIndex].getName() << "?" << endl;
                cout << "1: " << warriors[heroes[playerHeroIndex].getW1()].getName() << endl;
                cout << "2: " << warriors[heroes[playerHeroIndex].getW2()].getName() << endl;
                cout << "3: " << warriors[heroes[playerHeroIndex].getW3()].getName() << endl;
                cout << "4: " << warriors[heroes[playerHeroIndex].getW4()].getName() << endl;
                cout << "5: View stats" << endl;
                cout << "6: Don't release anyone (back)" << endl;
                
                while(!validInput2)
                {
                    cin >> choice;
                    choice = convertToLower(choice);

                    if (choice == "1")
                    {
                        heroes[playerHeroIndex].setW1(warriorIndex);
                        validInput2 = true;
                    }
                    else if (choice == "2")
                    {
                        heroes[playerHeroIndex].setW2(warriorIndex);
                        validInput2 = true;
                    }
                    else if (choice == "3")
                    {
                        heroes[playerHeroIndex].setW3(warriorIndex);
                        validInput2 = true;
                    }
                    else if (choice == "4")
                    {
                        heroes[playerHeroIndex].setW4(warriorIndex);
                        validInput2 = true;
                    }
                    else if (choice == "5")
                    {
                        cout << "Your warriors:" << endl;
                        viewWarriorStats(playerHeroIndex);
                        cout << "The warriors you may choose to obtain:" << endl;
                        warriors[warriorIndex].printUserSideStats();
                        cout << endl;
                        cout << "Who would you like to release in order to obtain " << warriors[warriorIndex].getName() << "?" << endl;
                        cout << "1: " << warriors[heroes[playerHeroIndex].getW1()].getName() << endl;
                        cout << "2: " << warriors[heroes[playerHeroIndex].getW2()].getName() << endl;
                        cout << "3: " << warriors[heroes[playerHeroIndex].getW3()].getName() << endl;
                        cout << "4: " << warriors[heroes[playerHeroIndex].getW4()].getName() << endl;
                        cout << "5: View stats" << endl;
                        cout << "6: Don't release anyone (back)" << endl;
                        validInput2 = false;
                    }
                    else if (choice == "6")
                    {
                        validInput2 = true;
                    }
                    else
                    {
                        cout << "Please enter a valid option." << endl;
                        validInput2 = false;
                    }
                }
                validInput = true;

            }
            else if (choice == "no" || choice == "n")
            {
                validInput = true;
            }
            else
            {
                cout << "Please enter a valid option: yes or no (y/n)" << endl;
            }
        }
    }
}

void Game::aiObtainWarrior(int heroIndex, int warriorIndex){ // basically the same as the player version except creates a random number instead of prompting one, and doesn't diplay any text
    int choice = 0;
    bool validInput = false;
    bool validInput2 = false;

    if (heroes[heroIndex].getW1() == -1)
    {
        cout << heroes[heroIndex].getName() << " has obtained " << warriors[warriorIndex].getName() << "!" << endl;
        heroes[heroIndex].setW1(warriorIndex);
    }
    else if (heroes[heroIndex].getW2() == -1)
    {
        cout << heroes[heroIndex].getName() << " has obtained " << warriors[warriorIndex].getName() << "!" << endl;
        heroes[heroIndex].setW2(warriorIndex);
    }
    else if (heroes[heroIndex].getW3() == -1)
    {
        cout << heroes[heroIndex].getName() << " has obtained " << warriors[warriorIndex].getName() << "!" << endl;
        heroes[heroIndex].setW3(warriorIndex);
    }
    else if (heroes[heroIndex].getW4() == -1)
    {
        cout << heroes[heroIndex].getName() << " has obtained " << warriors[warriorIndex].getName() << "!" << endl;
        heroes[heroIndex].setW4(warriorIndex);
    }
    else // hero has all 4 heroes
    {
        while(!validInput)
        {
            choice = rand() % 2;
            if (choice == 0) // if 0, choose a warrior to release
            {
                choice = rand() % 4;

                if (choice == 0) // depending on the random number, chooses a warrior to release
                {
                    cout << heroes[heroIndex].getName() << " has obtained " << warriors[warriorIndex].getName() << "!" << endl;
                    heroes[heroIndex].setW1(warriorIndex);
                    validInput2 = true;
                }
                else if (choice == 1)
                {
                    cout << heroes[heroIndex].getName() << " has obtained " << warriors[warriorIndex].getName() << "!" << endl;
                    heroes[heroIndex].setW2(warriorIndex);
                    validInput2 = true;
                }
                else if (choice == 2)
                {
                    cout << heroes[heroIndex].getName() << " has obtained " << warriors[warriorIndex].getName() << "!" << endl;
                    heroes[heroIndex].setW3(warriorIndex);
                    validInput2 = true;
                }
                else if (choice == 3)
                {
                    cout << heroes[heroIndex].getName() << " has obtained " << warriors[warriorIndex].getName() << "!" << endl;
                    heroes[heroIndex].setW4(warriorIndex);
                    validInput2 = true;
                }
                validInput = true;

            }
            else if (choice == 1) // if 1, keeps current warriors
            {
                validInput = true;
            }
        }
    }
}



                //printing things - some are for testing, some not

void Game::listWarriors(int heroIndex)
{
    if (heroes[heroIndex].getW1() != -1)
        cout << "Warrior 1: " << warriors[heroes[heroIndex].getW1()].getName();
    if (heroes[heroIndex].getW2() != -1)
        cout << " | Warrior 2: " << warriors[heroes[heroIndex].getW2()].getName();
    if (heroes[heroIndex].getW3() != -1)
        cout << " | Warrior 3: " << warriors[heroes[heroIndex].getW3()].getName();
    if (heroes[heroIndex].getW4() != -1)
        cout << " | Warrior 4: " << warriors[heroes[heroIndex].getW4()].getName();

    cout << endl;
}

void Game::printHeroesStats(){
    cout << "Stats of all Heroes:" << endl;
    for(unsigned int i = 0; i < heroesSize; i++)
    {
        heroes[i].printAllStats();
    }
}

void Game::printWarriorsStats(){
    cout << "Stats of all Warriors:" << endl;
    for(unsigned int i = 0; i < warriorsSize; i++)
    {
        warriors[i].printAllStats();
    }
}

void Game::viewWarriorStats(int heroIndex)
{
    if (heroes[heroIndex].getW1() > -1)
    {
        cout << "Warrior 1:" << endl;
        warriors[heroes[heroIndex].getW1()].printUserSideStats();
    }
    else
    {
        cout << "No warrior in slot 1 yet." << endl;
    }

    if (heroes[heroIndex].getW2() > -1)
    {
        cout << "Warrior 2:" << endl;
        warriors[heroes[heroIndex].getW2()].printUserSideStats();
    }
    else
    {
        cout << "No warrior in slot 2 yet." << endl;
    }

    if (heroes[heroIndex].getW3() > -1)
    {
        cout << "Warrior 3:" << endl;
        warriors[heroes[heroIndex].getW3()].printUserSideStats();
    }
    else
    {
        cout << "No warrior in slot 3 yet." << endl;
    }

    if (heroes[heroIndex].getW4() > -1)
    {
        cout << "Warrior 4:" << endl;
        warriors[heroes[heroIndex].getW4()].printUserSideStats();
    }
    else
    {
        cout << "No warrior in slot 4 yet." << endl;
    }
}

void Game::printWarriorsPositions(){ // for testing: printing out every stat can make the terminal cluttered, and many times only position and name is needed
    cout << "Positions of all Warriors:" << endl;
    for(unsigned int i = 0; i < warriorsSize; i++)
    {
        cout << warriors[i].getName() << ":" << endl;
        cout << "   R: " << warriors[i].getR();
        cout << "   C: " << warriors[i].getC() << endl;
    }
}

void Game::printCitiesStats(){
    cout << "Stats of all Cities:" << endl;
    for(unsigned int i = 0; i < citiesSize; i++)
    {
        cities[i].printAllStats();
    }
}

void Game::showWholeMap(){
    
    cout << "      0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  " << endl;
    cout << "    +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    for(int i = 0; i < 25; i++)
    {
        // printing the row numbers
        if (i < 10)
        {
            cout << i << ":  ";
        }
        else if (i >= 10)
        {
            cout << i << ": ";
        }
        // the first | character for each row; loop takes care of the rest
        cout << "| ";

        //
        for(int j = 0; j < 16; j++)
        {
            cout << tiles[i][j].getAttribute() << " | ";
        }
        cout << endl;


        cout << "    ";
        for(int j = 0; j < 16; j++)
        {
            cout << "+---";
        }
        cout  << "+" << endl;
    } 
}

void Game::showPlayerMap(){

    int tempR = heroes[playerHeroIndex].getR();
    int tempC = heroes[playerHeroIndex].getC();

    cout << "+---+---+---+---+---+---+---+" << endl;
    for(int i = 0; i < 7; i++)
    {
        cout << "| ";
        for(int j = 0; j < 7; j++)
        {
            if (((tempR + i - 3) < 0) || ((tempC + j - 3) < 0) || ((tempR + i - 3) >= tilesRows) || ((tempC + j - 3) >= tilesColumns)) // need this case to show the boundaries
            {
                cout << "/" << " | ";
            }
            else{
                cout << tiles[tempR + i - 3][tempC + j - 3].getAttribute() << " | ";
            }
        }
        cout << endl;

        for(int j = 0; j < 7; j++)
        {
            cout << "+---";
        }
        cout  << "+" << endl;
    } 

}



                // battle-related functions
                
bool Game::inFreeWarriorProximity(int hero, int warrior){
    int rDistance = abs(heroes[hero].getR() - warriors[warrior].getR());
    int cDistance = abs(heroes[hero].getC() - warriors[warrior].getC());
    if (rDistance <= 2 && cDistance <= 2)
    {
        return true;
    }
    return false;
}

int Game::checkFreeWarriorProximity(int heroInQuestion){
    
    for (unsigned int i = 0; i < warriorsSize; i++)
    {
        if (inFreeWarriorProximity(heroInQuestion, i) && warriors[i].getFree() == true)
        {
            warriors[i].setFree(false);
            if (heroInQuestion == playerHeroIndex)
            {
                playerObtainWarrior(i);
            }
            else
            {
                aiObtainWarrior(heroInQuestion, i);
            }
            return i;
            
        }
    }
    
    return -1; // -1 is fail, anything else is an index
}

bool Game::inProximity(int hero1, int hero2){ // helper function for checkProximity
    int rDistance = abs(heroes[hero1].getR() - heroes[hero2].getR());
    int cDistance = abs(heroes[hero1].getC() - heroes[hero2].getC());
    if (rDistance <= 2 && cDistance <= 2)
    {
        return true;
    }
    return false;
}

int Game::checkProximity(int heroInQuestion){
    
    for (unsigned int i = 0; i < heroesSize; i++)
    {
        if (i != heroInQuestion)
        {
            if (inProximity(heroInQuestion, i) && (heroes[heroInQuestion].getImmune() == false) && (heroes[i].getImmune() == false)) // after all proximities have been checked, all immunity is reset to false
            {
                heroes[heroInQuestion].setImmune(true);
                heroes[i].setImmune(true);
                //return i; // for testing; when actually running program, calls engage:
                engage(heroInQuestion, i);
            }
        }
    }

    return -1; // -1 is fail, anything else is an index
}

int Game::engage(int engagingHero, int defendingHero){
    int choice = -1;
    int result = -1;
    bool validInput = false;
    if (engagingHero == playerHeroIndex) 
    {
        cout << "You have encountered " << heroes[defendingHero].getName() << "! You have 3 choices: " << endl;
        cout << "1: Battle, 2: Buy their allegiance, 3: Give a speech." << endl;
        cout << "Type your choice as a number below:" << endl;

        choice = inputValidationInt("", 1, 3);
    }
    else 
    {
        cout << heroes[engagingHero].getName() << " has encountered " << heroes[defendingHero].getName() << "!" << endl;
        choice = (rand() % 3) + 1;
    }

    if (choice == 1) 
    {
        // cout << "Battle!" << endl;
        battle(engagingHero, defendingHero);
    }
    else if (choice == 2) 
    {
        // cout << "Bribery!" << endl;
        buyArmy(engagingHero, defendingHero);
    }
    else if (choice == 3) 
    {
        // cout << "Speech!" << endl;
        speech(engagingHero, defendingHero);
    }
    return 0;
}

int Game::battle(int engagingHero, int defendingHero){
    int engagingHeroStrength = 0;
    int defendingHeroStrength = 0;

    int engagingWarrior = -1;
    int defendingWarrior = -1;

// the edge cases, such as someone doesn't have a warrior
    if (heroes[engagingHero].getW1() == -1 && heroes[defendingHero].getW1() == -1)
    {
        cout << "Neither hero has a warrior, so the encounter will be decided by army size." << endl;

        if (heroes[engagingHero].getArmySize() > heroes[defendingHero].getArmySize()) // engaging wins
        {
            cout << heroes[defendingHero].getName() << " has been deleted." << endl;
            acquireAssets(engagingHero, defendingHero, 1, true);
            return 0;
        }
        else if (heroes[engagingHero].getArmySize() < heroes[defendingHero].getArmySize()) // defending wins
        {
            cout << heroes[engagingHero].getName() << " has been deleted." << endl;
            acquireAssets(defendingHero, engagingHero, 1, true);
            return 0;
        }
        else // tie
        {
            cout << heroes[engagingHero].getName() << " and " << heroes[defendingHero].getName() << " have tied!" << endl;
            return 0;
        }
    }
    else if (heroes[engagingHero].getW1() != -1 && heroes[defendingHero].getW1() == -1) // engaging wins
    {
        cout << heroes[engagingHero].getName() << " has a warrior and " << heroes[defendingHero].getName() << " does not, so " << heroes[engagingHero].getName() << " wins." << endl;
        cout << heroes[defendingHero].getName() << " has been deleted." << endl;
        acquireAssets(engagingHero, defendingHero, 1, true);
        return 0;
    }
    else if (heroes[engagingHero].getW1() == -1 && heroes[defendingHero].getW1() != -1) // defending wins
    {
        cout << heroes[defendingHero].getName() << " has a warrior and " << heroes[engagingHero].getName() << " does not, so " << heroes[defendingHero].getName() << " wins." << endl;
        cout << heroes[engagingHero].getName() << " has been deleted." << endl;
        acquireAssets(defendingHero, engagingHero, 1, true);
        return 0;
    }


//if they have multiple warriors, choose one
    if (engagingHero == playerHeroIndex)
    {
        cout << "Which warrior do you send out against " << heroes[defendingHero].getName() << "?" << endl;
        listWarriors(playerHeroIndex);

        if (heroes[playerHeroIndex].getW4() > -1)
        {
            engagingWarrior = inputValidationInt("", 1, 4);
        }
        else if (heroes[playerHeroIndex].getW3() > -1)
        {
            engagingWarrior = inputValidationInt("", 1, 3);
        }
        else if (heroes[playerHeroIndex].getW2() > -1)
        {
            engagingWarrior = inputValidationInt("", 1, 2);
        }
        else if (heroes[playerHeroIndex].getW1() > -1)
        {
            engagingWarrior = inputValidationInt("", 1, 1);
        }
        
        if (engagingWarrior == 1)
        {
            engagingHeroStrength = heroes[engagingHero].getArmySize() * warriors[heroes[engagingHero].getW1()].getStrength();   
        }
        else if (engagingWarrior == 2)
        {
            engagingHeroStrength = heroes[engagingHero].getArmySize() * warriors[heroes[engagingHero].getW1()].getStrength();   
        }
        else if (engagingWarrior == 3)
        {
            engagingHeroStrength = heroes[engagingHero].getArmySize() * warriors[heroes[engagingHero].getW1()].getStrength();   
        }
        else if (engagingWarrior == 4)
        {
            engagingHeroStrength = heroes[engagingHero].getArmySize() * warriors[heroes[engagingHero].getW1()].getStrength();   
        }
    }
    else 
    {
        engagingHeroStrength = heroes[engagingHero].getArmySize() * warriors[heroes[engagingHero].getW1()].getStrength();
    }
    
// the same thing except for when the player is defending instead of engaging
    if (defendingHero == playerHeroIndex)
    {
        cout << "Which warrior do you send out against " << heroes[defendingHero].getName() << "?" << endl;
        listWarriors(playerHeroIndex);
        cin >> defendingWarrior;
        if (defendingWarrior == 1)
        {
            defendingHeroStrength = heroes[defendingHero].getArmySize() * warriors[heroes[defendingHero].getW1()].getStrength();   
        }
        else if (defendingWarrior == 2)
        {
            defendingHeroStrength = heroes[defendingHero].getArmySize() * warriors[heroes[defendingHero].getW1()].getStrength();   
        }
        else if (defendingWarrior == 3)
        {
            defendingHeroStrength = heroes[defendingHero].getArmySize() * warriors[heroes[defendingHero].getW1()].getStrength();   
        }
        else if (defendingWarrior == 4)
        {
            defendingHeroStrength = heroes[defendingHero].getArmySize() * warriors[heroes[defendingHero].getW1()].getStrength();   
        }
    }
    else 
    {
        defendingHeroStrength = heroes[defendingHero].getArmySize() * warriors[heroes[defendingHero].getW1()].getStrength();
    }

// if all of the edge cases have been passed, finally compare the strength values
    if (engagingHeroStrength > defendingHeroStrength)
    { // engaging hero wins
        cout << heroes[defendingHero].getName() << " has been deleted." << endl;
        acquireAssets(engagingHero, defendingHero, 1, true);
    }
    else if (engagingHeroStrength < defendingHeroStrength) // the defending hero wins
    {
        cout << heroes[engagingHero].getName() << " has been deleted." << endl;
        acquireAssets(defendingHero, engagingHero, 1, true);
    }
    else  // tie
    {
        cout << heroes[engagingHero].getName() << " and " << heroes[defendingHero].getName() << " have tied!" << endl;
    }
    return 0;
}

int Game::buyArmy(int engagingHero, int defendingHero){ // when deciding the winner, use > or >= ?
    double chance = -1;
    if (heroes[engagingHero].getW1() != -1) // if they don't have a hero, chance will stay at 0 and loss will be unavoidable
    {                                 //shouldn't this be defendingHero ??? !!!
        chance = (1 - (warriors[heroes[engagingHero].getW1()].getLoyalty() / 100.0)) * (heroes[engagingHero].getMoney() / 20000.0);
    }

    int randomize = rand() % 1000; // I use 1000 instead of 100 to minimize the effect of rounding

    if (chance * 1000 >= randomize) // the engaging hero wins
    {
        cout << heroes[defendingHero].getName() << " has lost half their assets." << endl;  //if this happened when they had 0 warriors, it will delete the hero but not say it like it does in battle()
        acquireAssets(engagingHero, defendingHero, 0.5, false);
    }
    else // the defending hero wins
    {
        if (engagingHero == playerHeroIndex)
        {
            if (heroes[engagingHero].getW1() > -1) // if they don't have a warrior, I don't want to print "you escaped" becuase they lose if they don't have a warrior
            {
                cout << "You escaped, but lost half of your money." << endl;
            }
            acquireAssets(defendingHero, engagingHero, 0.5, false);
        }
        else
        {   //testing
            cout << heroes[engagingHero].getName() << " has lost half their assets." << endl;
            acquireAssets(defendingHero, engagingHero, 0.5, false);
        }
    }
    return 0;
}

int Game::speech(int engagingHero, int defendingHero){ // when deciding the winner, use > or >= ?
    // cout << "Engaging hero: " << heroes[engagingHero].getName() << endl;
    // listWarriors(engagingHero);
    // cout << "Defending hero: " << heroes[defendingHero].getName() << endl;
    // listWarriors(defendingHero);

    double chance = -1;
    if (heroes[engagingHero].getW1() > -1) // if they don't have a hero, chance will stay at 0 and loss will be unavoidable
    {                                //defendingHero???
        chance = (1 - (warriors[heroes[engagingHero].getW1()].getMorale() / 100.0)) * (heroes[engagingHero].getInfluence() / 1600.0);
    }

    int randomize = rand() % 1000; // I use 1000 instead of 100 to minimize the effect of rounding

    if (chance * 1000 >= randomize)  // the engaging hero wins
    {
        cout << heroes[defendingHero].getName() << " has lost half their assets." << endl;
        acquireAssets(engagingHero, defendingHero, 0.5, false);
    }
    else // the defending hero wins
    {
        if (engagingHero == playerHeroIndex)
        {
            if (heroes[engagingHero].getW1() > -1) // if they don't have a warrior, I don't want to print "you escaped" becuase they lose if they don't have a warrior
            {
                cout << "You escaped, but lost half of your influence." << endl;
            }
            acquireAssets(defendingHero, engagingHero, 0.5, false);
        }
        else
        {   //testing
            cout << heroes[engagingHero].getName() << " has lost half their assets." << endl;
            acquireAssets(defendingHero, engagingHero, 0.5, false);
        }
    }
    return 0;
}

int Game::acquireAssets(int winningHero, int losingHero, double factor, bool getAllWarriors){

    if (getAllWarriors == false) // when buyarmy or speech is called, the winner gets up to 1 warrior
    {
        obtainNewWarriors(winningHero, losingHero);
    }
    else // when battle is called, the winner gets all the loser's warriors
    {
        while (heroes[losingHero].getW1() > -1)
        {
            obtainNewWarriors(winningHero, losingHero);
        }
        obtainNewWarriors(winningHero, losingHero); // calling it one more time will remove the hero. I just do it here so I don't have to add removeHero to every case in the Battle function
    }
    

    // getting assets
    heroes[winningHero].setMoney(heroes[winningHero].getMoney() + (heroes[losingHero].getMoney() * factor));
    heroes[winningHero].setInfluence(heroes[winningHero].getInfluence() + (heroes[losingHero].getInfluence() * factor));
    heroes[winningHero].setArmySize(heroes[winningHero].getArmySize() + (heroes[losingHero].getArmySize() * factor));

    //decreasing loser's assets
    heroes[losingHero].setMoney(heroes[losingHero].getMoney() - (heroes[losingHero].getMoney() * factor));
    heroes[losingHero].setInfluence(heroes[losingHero].getInfluence() - (heroes[losingHero].getInfluence() * factor));
    heroes[losingHero].setArmySize(heroes[losingHero].getArmySize() - (heroes[losingHero].getArmySize() * factor));
    return 0;
}

void Game::removeHero(int heroIndex)
{
    if (heroIndex == playerHeroIndex)
    {
        endGame("lose");
    }
    else
    {
        if(heroIndex < playerHeroIndex){
            setPlayerHeroIndex(playerHeroIndex - 1);
        }
        for (unsigned int i = heroIndex + 1; i < heroesSize; i++)
        {
            heroes[i - 1].setName(heroes[i].getName());
            heroes[i - 1].setMoney(heroes[i].getMoney());
            heroes[i - 1].setInfluence(heroes[i].getInfluence());
            heroes[i - 1].setArmySize(heroes[i].getArmySize());
            heroes[i - 1].setW1(heroes[i].getW1());
            heroes[i - 1].setW2(heroes[i].getW2());
            heroes[i - 1].setW3(heroes[i].getW3());
            heroes[i - 1].setW4(heroes[i].getW4());
            heroes[i - 1].setR(heroes[i].getR());
            heroes[i - 1].setC(heroes[i].getC());
            heroes[i - 1].setShip(heroes[i].getShip());
            heroes[i - 1].setImmune(heroes[i].getImmune());

        }

        //just making sure the previous last hero isn't in there twice
        heroes[heroesSize - 1].setName("");
        heroes[heroesSize - 1].setMoney(0);
        heroes[heroesSize - 1].setInfluence(0);
        heroes[heroesSize - 1].setArmySize(0);
        heroes[heroesSize - 1].setW1(-1);
        heroes[heroesSize - 1].setW2(-1);
        heroes[heroesSize - 1].setW3(-1);
        heroes[heroesSize - 1].setW4(-1);
        heroes[heroesSize - 1].setR(-99);
        heroes[heroesSize - 1].setC(-99);
        heroes[heroesSize - 1].setShip(false);
        heroes[heroesSize - 1].setImmune(false);

        heroesSize = heroesSize - 1;

        cout << "The heroes that are now left are: " << endl;
        for (unsigned int i = 0; i < heroesSize; i++)
        {
            cout << heroes[i].getName() << endl;
        }
    }
}

double Game::calculatePowerScore(){
    double powerScore = heroes[playerHeroIndex].getArmySize();
    int cityControlCounter = 0;

    // adding the stats from every warrior
    if (heroes[playerHeroIndex].getW1() > -1)
    {  
        powerScore = powerScore + warriors[heroes[playerHeroIndex].getW1()].getStrength() * (warriors[heroes[playerHeroIndex].getW1()].getMorale() / 50.00);
    }
    if (heroes[playerHeroIndex].getW2() > -1)
    {  
        powerScore = powerScore + warriors[heroes[playerHeroIndex].getW1()].getStrength() * (warriors[heroes[playerHeroIndex].getW2()].getMorale() / 50.00);
    }
    if (heroes[playerHeroIndex].getW3() > -1)
    {  
        powerScore = powerScore + warriors[heroes[playerHeroIndex].getW1()].getStrength() * (warriors[heroes[playerHeroIndex].getW3()].getMorale() / 50.00);
    }
    if (heroes[playerHeroIndex].getW4() > -1)
    {  
        powerScore = powerScore + warriors[heroes[playerHeroIndex].getW1()].getStrength() * (warriors[heroes[playerHeroIndex].getW4()].getMorale() / 50.00);
    }

    //adding the score from cities/influence
    for (unsigned int i = 0; i < citiesSize; i++)
    {
        if (cities[i].getBelongsToHero() == playerHeroIndex)
        {
            cityControlCounter++;
        }
    }
    powerScore = powerScore + ((cityControlCounter + 1.00) * (heroes[playerHeroIndex].getInfluence() / 4.00));

    // if warriors have dragonglass
    if (warriors[heroes[playerHeroIndex].getW1()].getHasDragonglass())
    {
        powerScore = powerScore + 10000.00;
    }
    if (warriors[heroes[playerHeroIndex].getW2()].getHasDragonglass())
    {
        powerScore = powerScore + 10000.00;
    }
    if (warriors[heroes[playerHeroIndex].getW3()].getHasDragonglass())
    {
        powerScore = powerScore + 10000.00;
    }
    if (warriors[heroes[playerHeroIndex].getW4()].getHasDragonglass())
    {
        powerScore = powerScore + 10000.00;
    }

    return powerScore;
}

int Game::fightWhiteWalkers(){
    double powerScore = calculatePowerScore();
    int randNum = 0;
    int totalDragonglass = 0;
    int dragonglassUsed = 0;

//counting dragonglass
    if (warriors[heroes[playerHeroIndex].getW1()].getHasDragonglass())
    {
        totalDragonglass++;
    }
    if (warriors[heroes[playerHeroIndex].getW2()].getHasDragonglass())
    {
        totalDragonglass++;
    }
    if (warriors[heroes[playerHeroIndex].getW3()].getHasDragonglass())
    {
        totalDragonglass++;
    }
    if (warriors[heroes[playerHeroIndex].getW4()].getHasDragonglass())
    {
        totalDragonglass++;
    }

        cout << "Your power score is: " << powerScore << endl;
        cout << "Your total dragonglass is: " << totalDragonglass << endl;
        cout << "Your chances are: " << ((1 - (1 / exp(powerScore / 30000))) * 1000) / 10 << "%" << endl;

    for(int i = 0; i < totalDragonglass; i++)
    {
        dragonglassUsed++;
        randNum = rand() % 1000;
        cout << "The random number is: " << randNum / 10 << endl;
        if (randNum < ((1.0 - (1.0 / exp(powerScore / 30000.0))) * 1000.0))
        {
            endGame("win");
            return dragonglassUsed; // win
        }
    }

    endGame("lose");
    return -1; // loss
}

                //high-level functions 

void Game::moveEveryone(){
    gameEnd = false;
    int walkerCounter = 0;
    int playerChoice = 1;
    bool isPlayersTurn = true;
    char playerResponse = 'a';

    while (!gameEnd)
    {

        showPlayerMap();
        //moving heroes
        for (unsigned int i = 0; i < heroesSize; i++)
        {
            if (i == playerHeroIndex && !gameEnd)
            {
                //print their hero's stats
                cout << "Your stats (" << heroes[playerHeroIndex].getName() << "):";
                cout << "   Money: " << heroes[playerHeroIndex].getMoney();
                cout << "   Army size: " << heroes[playerHeroIndex].getArmySize();
                cout << "   Influence: " << heroes[playerHeroIndex].getInfluence() << endl;
                isPlayersTurn = true;

                while (isPlayersTurn)
                {
                    playerChoice = inputValidationInt("Choose an option:    1: Travel    2: Rest    3: Consult with the gods    4: View warrior stats    5: Reorder warriors", 1, 5);
                    if (playerChoice == 1)
                    {
                        moveHero(i);
                        getTileResources(i);
                        isPlayersTurn = false;
                    }
                    else if (playerChoice == 2)
                    {
                        rest();
                        isPlayersTurn = false;
                    }
                    else if (playerChoice == 3)
                    {
                        consult();
                        isPlayersTurn = false;
                    }
                    else if (playerChoice == 4)
                    {
                        viewWarriorStats(playerHeroIndex);
                        //continue input loop
                    }
                    else if (playerChoice == 5)
                    {
                        reorderWarriors();
                        //continue input loop
                    }
                }
            }
            else if (!gameEnd)
            {
                moveHero(i);
                getTileResources(i);
            }
        }
        //moving free warriors
        for (unsigned int i = 0; i < warriorsSize; i++)
        {
            if (warriors[i].getFree() == true && !gameEnd)
            {
                moveFreeWarrior(i);
                freeWarriorFindDragonglass(i);
            }
        }
        //checking all proximity and engaging fights
        for (unsigned int i = 0; i < heroesSize; i++)
        {
            if (!gameEnd)
            {
                checkFreeWarriorProximity(i);
                checkProximity(i);
            }
        }
        //resetting all immunity
        for (unsigned int i = 0; i < heroesSize; i++)
        {
            heroes[i].setImmune(false);
        }

        //boss fight
        if (turns >= 50 || heroes[playerHeroIndex].getArmySize() >= 2000 || heroesSize == 1)
        {
            if (walkerCounter < 5)
            {
                
                playerResponse = inputValidationChar("The white walkers are approaching. Face them now? (y/n)", 'y', 'Y', 'n', 'N');
                if (playerResponse == 'y' || playerResponse == 'Y')
                {
                    fightWhiteWalkers();
                }
                walkerCounter++;
            }
            else
            {
                cout << "You've denied the boss fight the maximum of 5 times. You must now fight the boss." << endl;
                fightWhiteWalkers();
            }
        }

        turns++;
    }
}

void Game::endGame(string winOrLose){

    if (winOrLose == "win")
    {
        cout << "Congratulations! You have won the game." << endl;
    }
    else 
    {
        cout << "Too bad. You lost." << endl;
    }
    gameEnd = true;
    writeGameStats("resultsGOT.txt");
}


                // file reading
                
int Game::readTiles(string fileName, int tilesArraySize) {
    // file opening shenanigans
    ifstream inputFile;
    inputFile.open(fileName);

    // if it was a success
    if (inputFile.is_open())
    {
        // setting up variables for reading the file and counting
        string line = ""; // each line of the file is stored in here
        string temp = ""; // while traversing line, strings are kept here and then stored into a variable 
        //int lineidx = 0; // purely for printing back to terminal for testing
        int k = 0; // to determine what row to store in
        int j = 0; // to determine what column to store in

        // while the file hasn't been completely read yet AND there's still space
        while (getline(inputFile, line) && k < (tilesArraySize))
        {
            if (line != "") // if line isn't empty
            {
                j = 0;
                temp = "";

                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                line = line.substr(0, (line.length() - 1)); // attempting to remove hidden encoding characters 
                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                line = line + ","; // adding delimiter so that we can successfully get the last element in each line
                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                
                //printing the line back to terminal for testing reasons
                //cout << "lineidx: " << lineidx << ": " << line << endl;
                //lineidx++;

                for (int i = 0; i < line.length(); i++)
                {   
                    // printing out the character for testing purposes
                    //cout << "line[" << i << "] " << line[i] << endl;

                    // building a string until we hit a ','
                    if (line[i] != ',') 
                    {
                        temp += line[i];
                    }
                    else
                    {
                        if (temp == "p")
                        {
                            tiles[k][j].setAttribute("#");
                        }
                        else if (temp == "w")
                        {
                            tiles[k][j].setAttribute(" ");
                        }
                        else 
                        {
                            tiles[k][j].setAttribute(temp);
                            tiles[k][j].setCityIndex(int(temp[0]) - 65);
                        }
                        j++;
                        temp = "";
                    }
                }
                k++;
            }
        }
        //function end and returning
        inputFile.close();
        return k; // the number of tiles
    }
    else 
    {
        //function end and returning
        cout << "Could not open file." << endl;
        inputFile.close();
        return -1;
    }
}

//helper:
void Game::assignCityPositions(int cityIndex){
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            if (tiles[i][j].getAttribute()[0] == cities[cityIndex].getLetter())
            {
                cities[cityIndex].setR(i);
                cities[cityIndex].setC(j);
            }
        }
    } 
}

int Game::readHeroes(string fileName, int heroesArraySize){
    // file opening shenanigans
    ifstream inputFile;
    inputFile.open(fileName);

    // if it was a success
    if (inputFile.is_open())
    {
        // setting up variables for reading the file and counting
        string line = ""; // each line of the file is stored in here
        string temp = ""; // while traversing line, strings are kept here and then stored into a variable 
        //int lineidx = 0; // purely for printing back to terminal for testing
        int k = 0; // to determine what row to store in
        int j = 0; // to determine what column to store in

        // while the file hasn't been completely read yet AND there's still space
        while (getline(inputFile, line) && k < (heroesArraySize))
        {
            if (line != "") // if line isn't empty
            {
                j = 0;
                temp = "";

                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                line = line.substr(0, (line.length() - 1)); // attempting to remove hidden encoding characters 
                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                line = line + ","; // adding delimiter so that we can successfully get the last element in each line
                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                
                //printing the line back to terminal for testing reasons
                //cout << "lineidx: " << lineidx << ": " << line << endl;
                //lineidx++;

                for (int i = 0; i < line.length(); i++)
                {   
                    // printing out the character for testing purposes
                    //cout << "line[" << i << "] " << line[i] << endl;

                    // building a string until we hit a ','
                    if (line[i] != ',') 
                    {
                        temp += line[i];
                    }
                    else if(j == 0)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setName(temp);
                        j++;
                        temp = "";
                    }
                    else if(j == 1)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setMoney(stoi(temp));
                        j++;
                        temp = "";
                    }
                    else if(j == 2)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setInfluence(stoi(temp));
                        j++;
                        temp = "";
                    }
                    else if(j == 3)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setArmySize(stoi(temp));
                        j++;
                        temp = "";
                    }
                    else if(j == 4)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setW1(findWarrior(temp)); 
                        j++;
                        temp = "";
                    }
                    else if(j == 5)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setW2(findWarrior(temp)); 
                        j++;
                        temp = "";
                    }
                    else if(j == 6)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setW3(findWarrior(temp)); 
                        j++;
                        temp = "";
                    }
                    else if(j == 7)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setW4(findWarrior(temp)); 
                        j++;
                        temp = "";
                    }
                    else if(j == 8)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setR(stoi(temp));
                        j++;
                        temp = "";
                    }
                    else if(j == 9)
                    {
                        //cout << "Temp: " << temp << endl;
                        heroes[k].setC(stoi(temp));
                        j++;
                        temp = "";
                    }
                    else if(j == 10)
                    {
                        //cout << "Temp: " << temp << endl;
                        if (temp == "yes")
                        {
                        heroes[k].setShip(true);
                        }
                        else
                        {
                        heroes[k].setShip(false);
                        }
                        j++;
                        temp = "";
                    }
                }
                k++;
            }
        }
        //function end and returning
        inputFile.close();
        return k; // the number of heroes
    }
    else 
    {
        //function end and returning
        cout << "Could not open file." << endl;
        inputFile.close();
        return -1;
    }
}

int Game::readWarriors(string fileName, int warriorsArraySize){
    // file opening shenanigans
    ifstream inputFile;
    inputFile.open(fileName);

    // if it was a success
    if (inputFile.is_open())
    {
        // setting up variables for reading the file and counting
        string line = ""; // each line of the file is stored in here
        string temp = ""; // while traversing line, strings are kept here and then stored into a variable 
        //int lineidx = 0; // purely for printing back to terminal for testing
        int k = 0; // to determine what row to store in
        int j = 0; // to determine what column to store in

        // while the file hasn't been completely read yet AND there's still space
        while (getline(inputFile, line) && k < (warriorsArraySize))
        {
            if (line != "") // if line isn't empty
            {
                j = 0;
                temp = "";

                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                line = line.substr(0, (line.length() - 1)); // attempting to remove hidden encoding characters 
                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                line = line + ","; // adding delimiter so that we can successfully get the last element in each line
                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                
                //printing the line back to terminal for testing reasons
                //cout << "lineidx: " << lineidx << ": " << line << endl;
                //lineidx++;

                for (int i = 0; i < line.length(); i++)
                {   
                    // printing out the character for testing purposes
                    //cout << "line[" << i << "] " << line[i] << endl;

                    // building a string until we hit a ','
                    if (line[i] != ',') 
                    {
                        temp += line[i];
                    }
                    else if(j == 0)
                    {
                        //cout << "Temp: " << temp;
                        warriors[k].setName(temp);
                        j++;
                        temp = "";
                    }
                    else if(j == 1)
                    {
                        //cout << "Temp: " << temp << endl;
                        warriors[k].setStrength(stoi(temp));
                        j++;
                        temp = "";
                    }
                    else if(j == 2)
                    {
                        //cout << "Temp: " << temp << endl;
                        warriors[k].setLoyalty(stoi(temp));
                        j++;
                        temp = "";
                    }
                    else if(j == 3)
                    {
                        //cout << "Temp: " << temp << endl;
                        warriors[k].setMorale(stoi(temp));
                        j++;
                        temp = "";
                    }
                    else if(j == 4)
                    {
                        //cout << "Temp: " << temp << endl;
                        if (temp == "yes")
                        {
                        warriors[k].setFree(true);
                        }
                        else
                        {
                        warriors[k].setFree(false);
                        }
                        j++;
                        temp = "";
                    }
                    else if(j == 5)
                    {
                        //cout << "Temp: " << temp << endl;
                        if (temp == "yes")
                        {
                        warriors[k].setShip(true);
                        }
                        else
                        {
                        warriors[k].setShip(false);
                        }
                        j++;
                        temp = "";
                    }
                    else if(j == 6)
                    {
                        //cout << "Temp: " << temp << endl;
                        if (temp == "yes")
                        {
                        warriors[k].setHasDragonglass(true);
                        }
                        else
                        {
                        warriors[k].setHasDragonglass(false);
                        }
                        j++;
                        temp = "";
                    }
                }
                k++;
            }
        }
        //function end and returning
        inputFile.close();
        return k; // the number of warriors
    }
    else 
    {
        //function end and returning
        cout << "Could not open file." << endl;
        inputFile.close();
        return -1;
    }
}

int Game::readCities(string fileName, int citiesArraySize){
    // file opening shenanigans
    ifstream inputFile;
    inputFile.open(fileName);

    // if it was a success
    if (inputFile.is_open())
    {
        // setting up variables for reading the file and counting
        string line = ""; // each line of the file is stored in here
        string temp = ""; // while traversing line, strings are kept here and then stored into a variable 
        //int lineidx = 0; // purely for printing back to terminal for testing
        int k = 0; // to determine what row to store in
        int j = 0; // to determine what column to store in

        // while the file hasn't been completely read yet AND there's still space
        while (getline(inputFile, line) && k < (citiesArraySize))
        {
            if (line != "") // if line isn't empty
            {
                j = 0;
                temp = "";

                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                line = line.substr(0, (line.length() - 1)); // attempting to remove hidden encoding characters 
                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                line = line + ","; // adding delimiter so that we can successfully get the last element in each line
                    //cout << "line: " << line << endl; // printing to make sure removing hidden characters doesn't do anything unintentional
                
                //printing the line back to terminal for testing reasons
                //cout << "lineidx: " << lineidx << ": " << line << endl;
                //lineidx++;

                for (int i = 0; i < line.length(); i++)
                {   
                    // printing out the character for testing purposes
                    //cout << "line[" << i << "] " << line[i] << endl;

                    // building a string until we hit a ','
                    if (line[i] != ',') 
                    {
                        temp += line[i];
                    }
                    else if(j == 0)
                    {
                        //cout << "Temp: " << temp << endl;
                        cities[k].setLetter(temp[0]);
                        assignCityPositions(k);
                        j++;
                        temp = "";
                    }
                    else if(j == 1)
                    {
                        //cout << "Temp: " << temp << endl;
                        cities[k].setName(temp);
                        j++;
                        temp = "";
                    }
                    else if(j == 2)
                    {
                        //cout << "Temp: " << temp << endl;
                        cities[k].setMoney(stoi(temp));
                        j++;
                        temp = "";
                    }
                    else if(j == 3)
                    {
                        //cout << "Temp: " << temp << endl;
                        cities[k].setArmySize(stoi(temp));
                        j++;
                        temp = "";
                    }
                }
                k++;
            }
        }
        //function end and returning
        inputFile.close();
        return k; // the number of cities
    }
    else 
    {
        //function end and returning
        cout << "Could not open file." << endl;
        inputFile.close();
        return -1;
    }
}

int Game::writeGameStats(string fileName){

    //writes to a file "resultsGOT.txt"
    ofstream outputFile;
    outputFile.open(fileName);

    // Format: <Username> <Hero Name> <Main Warrior> <Money> <Influence> <Army Size>
    outputFile << "<" << "Hero Name" << "> <" << "Main Warrior" << "> <" << "Money" << "> <" << "Influence" << "> <" << "Army Size" << ">" << endl;
    
                                                                    //this causes error when lose, because no warriors exist
    outputFile << "<" << heroes[playerHeroIndex].getName() << "> <" << warriors[heroes[playerHeroIndex].getW1()].getName() << "> <" << heroes[playerHeroIndex].getMoney() << "> <" << heroes[playerHeroIndex].getInfluence() << "> <" << heroes[playerHeroIndex].getArmySize() << ">" << endl;

    outputFile.close();
    return 0;
}