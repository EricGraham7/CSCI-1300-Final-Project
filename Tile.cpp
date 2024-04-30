// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3 - Tile class

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include "Tile.h"
#include "City.h"
using namespace std;

Tile::Tile()
{    
    attribute = "";
    hasDragonglass = false;
    cityIndex = -1;
    r = 0;
    c = 0;
}
Tile::Tile(string attributeIn, bool hasDragonglassIn, int cityIndexIn, int rIn, int cIn)
{
    attribute = attributeIn;
    hasDragonglass = hasDragonglassIn;
    cityIndex = cityIndexIn;
    r = rIn;
    c = cIn;
}
void Tile::setAttribute(string attributeIn)
{
    attribute = attributeIn;
}
void Tile::setHasDragonglass(bool hasDragonglassIn)
{
    hasDragonglass = hasDragonglassIn;    
}
void Tile::setCityIndex(int cityIndexIn){
    cityIndex = cityIndexIn;
}
void Tile::setR(int rIn)
{
    r = rIn;
}
void Tile::setC(int cIn)
{
    c = cIn;
}
// void Tile::setCity(City cityIn)
// {
//     city.setLetter(cityIn.getLetter());
//     city.setName(cityIn.getName());
//     city.setMoney(cityIn.getMoney());
//     city.setArmySize(cityIn.getArmySize());
//     city.setPoints(cityIn.getPoints());
//     city.setR(cityIn.getR());
//     city.setC(cityIn.getC());
// }

string Tile::getAttribute()
{
    return attribute;
}
bool Tile::getHasDragonglass()
{
    return hasDragonglass;
}
int Tile::getCityIndex(){
    return cityIndex;
}
int Tile::getR()
{
    return r;
}
int Tile::getC()
{
    return c;
}
// City Tile::getCity()
// {
//     return city;
// }
void Tile::printAllStats() // for testing. Helpful to have a function like this
{
    cout << "Attribute: " << attribute << endl;
    cout << "Has dragonglass: " << hasDragonglass << endl;
    cout << "City index: " << cityIndex << endl;
    cout << "R: " << r << endl;
    cout << "C: " << c << endl;
}