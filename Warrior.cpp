// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - Warrior class

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include "Warrior.h"
using namespace std;

Warrior::Warrior()
{    
    name = "";
    strength = 0;
    loyalty = 0;
    morale = 0;
    free = false;
    ship = false;
    hasDragonglass = false;
    r = 0;
    c = 0;
}
Warrior::Warrior(string nameIn, int strengthIn, int loyaltyIn, int moraleIn, bool freeIn, bool shipIn, bool hasDragonglassIn, int rIn, int cIn)
{
    name = nameIn;
    strength = strengthIn;
    loyalty = loyaltyIn;
    morale = moraleIn;
    free = freeIn;
    ship = shipIn;
    hasDragonglass = hasDragonglassIn;
    r = rIn;
    c = cIn;
}
void Warrior::setName(string nameIn)
{
    name = nameIn;
}
void Warrior::setStrength(int strengthIn)
{
    strength = strengthIn;
}
void Warrior::setLoyalty(int loyaltyIn)
{
    loyalty = loyaltyIn;
}
void Warrior::setMorale(int moraleIn)
{
    morale = moraleIn;
}
void Warrior::setFree(bool freeIn)
{
    free = freeIn;
}
void Warrior::setShip(bool shipIn)
{
    ship = shipIn;
}
void Warrior::setHasDragonglass(bool hasDragonglassIn)
{
    hasDragonglass = hasDragonglassIn;    
}
void Warrior::setR(int rIn)
{
    r = rIn;
}
void Warrior::setC(int cIn)
{
    c = cIn;
}

void Warrior::travel(char direction, int distance)
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

string Warrior::getName()
{
    return name;
}
int Warrior::getStrength()
{
    return strength;
}
int Warrior::getLoyalty()
{
    return loyalty;
}
int Warrior::getMorale()
{
    return morale;
}
bool Warrior::getFree()
{
    return free;
}
bool Warrior::getShip()
{
    return ship;
}
bool Warrior::getHasDragonglass()
{
    return hasDragonglass;
}
int Warrior::getR()
{
    return r;
}
int Warrior::getC()
{
    return c;
}
void Warrior::printAllStats() // for testing. Helpful to have a function like this
{
    cout << "Name: " << name << endl;
    cout << "Strength: " << strength << endl;
    cout << "Loyalty: " << loyalty << endl;
    cout << "Morale: " << morale << endl;
    cout << "Free: " << free << endl;
    cout << "Ship: " << ship << endl;
    cout << "Has dragonglass: " << hasDragonglass << endl;
    cout << "R: " << r << endl;
    cout << "C: " << c << endl;
}

void Warrior::printUserSideStats(){
    cout << "Name: " << name << endl;
    cout << "Strength: " << strength;
    cout << "   Loyalty: " << loyalty;
    cout << "   Morale: " << morale << endl;
    if (ship == true)
    {
        cout << "Ship: Yes";
    }
    else
    {
        cout << "Ship: No";
    }
    if (hasDragonglass == true)
    {
        cout << "       Dragonglass: Yes" << endl;
    }
    else
    {
        cout << "       Dragonglass: No" << endl;
    }
}