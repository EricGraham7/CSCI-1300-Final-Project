// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - Hero class

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include "Hero.h"
using namespace std;

Hero::Hero()
{    
    name = "";
    money = 0;
    influence = 0;
    armySize = 0;
    w1 = 0;
    w2 = 0;
    w3 = 0;
    w4 = 0;
    r = 0;
    c = 0;
    ship = false;
    immune = false;
}
Hero::Hero(string nameIn, int moneyIn, int influenceIn, int armySizeIn, int w1In, int w2In, int w3In, int w4In, int rIn, int cIn, bool shipIn)
{
    name = nameIn;
    money = moneyIn;
    influence = influenceIn;
    armySize = armySizeIn;
    w1 = w1In;
    w2 = w2In;
    w3 = w3In;
    w4 = w4In;
    r = rIn;
    c = cIn;
    ship = shipIn;
    immune = false;
}
void Hero::setName(string nameIn)
{
    name = nameIn;
}
void Hero::setMoney(int moneyIn)
{
    money = moneyIn;
}
void Hero::setInfluence(int influenceIn)
{
    influence = influenceIn;
}
void Hero::setArmySize(int armySizeIn)
{
    armySize = armySizeIn;
}
void Hero::setW1(int w1In) // should be setting a Hero, not string?
{
    w1 = w1In;
}
void Hero::setW2(int w2In) // should be setting a Hero, not string?
{
    w2 = w2In;
}
void Hero::setW3(int w3In) // should be setting a Hero, not string?
{
    w3 = w3In;
}
void Hero::setW4(int w4In) // should be setting a Hero, not string?
{
    w4 = w4In;
}
void Hero::setR(int rIn)
{
    r = rIn;
}
void Hero::setC(int cIn)
{
    c = cIn;
}
void Hero::setShip(bool shipIn)
{
    ship = shipIn;
}
void Hero::setImmune(bool immuneIn){
    immune = immuneIn;
}


void Hero::travel(char direction, int distance)
{
    switch (direction)
    {
        case 'n':
        case 'N':
            r = r - distance;
            break;
        case 'e':
        case 'E':
            c = c + distance;
            break;
        case 's':
        case 'S':
            r = r + distance;
            break;
        case 'w':
        case 'W':
            c = c - distance;
            break;
    }
}

string Hero::getName()
{
    return name;
}
int Hero::getMoney()
{
    return money;
}
int Hero::getInfluence()
{
    return influence;
}
int Hero::getArmySize()
{
    return armySize;
}
int Hero::getW1()
{
    return w1;
}
int Hero::getW2()
{
    return w2;
}
int Hero::getW3()
{
    return w3;
}
int Hero::getW4()
{
    return w4;
}
int Hero::getR()
{
    return r;
}
int Hero::getC()
{
    return c;
}
bool Hero::getShip()
{
    return ship;
}
bool Hero::getImmune()
{
    return immune;
}
void Hero::printAllStats() // for testing. Helpful to have a function like this
{
    cout << "Name: " << name << endl;
    cout << "Money: " << money << endl;
    cout << "Influence: " << influence << endl;
    cout << "Army size: " << armySize << endl;
    cout << "Warrior 1: " << w1 << endl;
    cout << "Warrior 2: " << w2 << endl;
    cout << "Warrior 3: " << w3 << endl;
    cout << "Warrior 4: " << w4 << endl;
    cout << "R: " << r << endl;
    cout << "C: " << c << endl;
    cout << "Ship: " << ship << endl;
    cout << "Immunity: " << immune << endl;
}