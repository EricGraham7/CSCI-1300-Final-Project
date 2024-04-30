// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - Hero class

#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

class Hero
{
    public:
        Hero();
        Hero(string nameIn, int moneyIn, int influenceIn, int armySizeIn, int w1In, int w2In, int w3In, int w4In, int rIn, int cIn, bool shipIn);
        void setName(string nameIn);
        void setMoney(int moneyIn);
        void setInfluence(int influenceIn);
        void setArmySize(int armySizeIn);
        void setW1(int w1In);
        void setW2(int w2In);
        void setW3(int w3In);
        void setW4(int w4In);
        void setR(int rIn);
        void setC(int cIn);
        void setShip(bool shipIn);
        void setImmune(bool immuneIn);

        void travel(char direction, int distance);

        string getName();
        int getMoney();
        int getInfluence();
        int getArmySize();
        int getW1();
        int getW2();
        int getW3();
        int getW4();
        int getR();
        int getC();
        bool getShip();
        bool getImmune();

        void printAllStats();

    private:
        string name;
        int money;
        int influence;
        int armySize;
        int w1;
        int w2;
        int w3;
        int w4;
        int r;
        int c;
        bool ship;
        bool immune;
};

#endif