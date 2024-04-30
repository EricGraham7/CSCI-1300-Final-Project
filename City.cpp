// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - City class

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include "City.h"
using namespace std;

City::City()
{    
    letter = 'a';
    name = "";
    money = 0;
    armySize = 0;
    r = 0;
    c = 0;
    belongsToHero = -1;
}
City::City(char letterIn, string nameIn, int moneyIn, int armySizeIn, int rIn, int cIn, int heroIndexIn)
{
    letter = letterIn;
    name = nameIn;
    money = moneyIn;
    armySize = armySizeIn;
    r = rIn;
    c = cIn;
    belongsToHero = heroIndexIn;
}
void City::setLetter(char letterIn)
{
    letter = letterIn;
}
void City::setName(string nameIn)
{
    name = nameIn;
}
void City::setMoney(int moneyIn)
{
    money = moneyIn;
}
void City::setArmySize(int armySizeIn)
{
    armySize = armySizeIn;
}
void City::setR(int rIn)
{
    r = rIn;
}
void City::setC(int cIn)
{
    c = cIn;
}
void City::setBelongsToHero(int heroIndexIn)
{
    belongsToHero = heroIndexIn;
}


char City::getLetter()
{
    return letter;
}
string City::getName()
{
    return name;
}
int City::getMoney()
{
    return money;
}
int City::getArmySize()
{
    return armySize;
}
int City::getR()
{
    return r;
}
int City::getC()
{
    return c;
}
int City::getBelongsToHero()
{
    return belongsToHero;
}

void City::printAllStats() // for testing. Helpful to have a function like this
{
    cout << "Letter: " << letter << endl;
    cout << "Name: " << name << endl;
    cout << "Money: " << money << endl;
    cout << "Army size: " << armySize << endl;
    cout << "R: " << r << endl;
    cout << "C: " << c << endl;
    cout << "Belongs to hero of index: " << belongsToHero << endl;
}