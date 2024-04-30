// CS1300 Fall 2020
// Author: Eric Graham
// Recitation: 207 - Steven Wilmes and Justus Griego
// Project 3

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

// I wrote these outside of the game class, tested them, and then put them into the .cpp and h files

int inputValidationInt(string message, int rangeFloor, int rangeCeiling){
    string userInput = "";
    bool isValidInput = false;

    cout << message << endl;

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


char inputValidationChar(string message, char option1, char option2, char option3, char option4){
    string userInput = "";
    bool isValidInput = false;

    cout << message << endl;

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

int main(){

    cout << inputValidationInt("Please enter an integer.", 0, 7) << endl;
    cout << inputValidationChar("Please enter a character.", 'n', 'e', 's', 'w') << endl;

    return 0;
}