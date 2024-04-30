// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - Warrior class

#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

class Warrior
{
    public:
        Warrior();
        Warrior(string nameIn, int strengthIn, int loyaltyIn, int moraleIn, bool freeIn, bool shipIn, bool hasDragonglassIn, int rIn, int cIn);
        void setName(string nameIn);
        void setStrength(int strengthIn);
        void setLoyalty(int loyaltyIn);
        void setMorale(int moraleIn);
        void setFree(bool freeIn);
        void setShip(bool shipIn);
        void setHasDragonglass(bool hasDragonglassIn);
        void setR(int rIn);
        void setC(int cIn);

        void travel(char direction, int distance);
        
        string getName();
        int getStrength();
        int getLoyalty();
        int getMorale();
        bool getFree();
        bool getShip();
        bool getHasDragonglass();
        int getR();
        int getC();

        void printAllStats();
        void printUserSideStats();
    private:
        string name;
        int strength;
        int loyalty;
        int morale;
        bool free;
        bool ship;
        bool hasDragonglass;
        int r;
        int c;
};

#endif