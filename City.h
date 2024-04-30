// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - City class

#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

class City
{
    public:
        City();
        City(char letterIn, string nameIn, int moneyIn, int armySizeIn, int rIn, int cIn, int heroIndexIn);

        void setLetter(char letterIn);
        void setName(string nameIn);
        void setMoney(int moneyIn);
        void setArmySize(int armySizeIn);
        void setR(int rIn);
        void setC(int cIn);
        void setBelongsToHero(int heroIndexIn);

        char getLetter();
        string getName();
        int getMoney();
        int getArmySize();
        int getR();
        int getC();
        int getBelongsToHero();

        void printAllStats();

    private:
        char letter;
        string name;
        int money;
        int armySize;
        int r;
        int c;
        int belongsToHero;
};

#endif