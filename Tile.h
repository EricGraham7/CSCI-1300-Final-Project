// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - Tile class

#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

class Tile
{
    public:
        Tile();
        Tile(string attributeIn, bool hasDragonglassIn, int cityIndexIn, int rIn, int cIn);
        void setAttribute(string attributeIn);
        void setHasDragonglass(bool hasDragonglassIn);
        void setCityIndex(int cityIndexIn);
        void setR(int rIn);
        void setC(int cIn);
        //void setCity(City cityIn);
        
        string getAttribute();
        bool getHasDragonglass();
        int getCityIndex();
        int getR();
        int getC();
        //City getCity();

        void printAllStats();
    private:
        string attribute;
        bool hasDragonglass;
        int cityIndex;
        // hasWarrior
        // hasHero
        int r;
        int c;
};

#endif