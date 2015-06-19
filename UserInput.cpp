//
// ************************************************************************************
// 
// Class:   PCC CS162
// Lab:     5
// Project: Task Tracker - UserInput.cpp
//
// Student: Erik Ratcliffe
// Date   : November 24, 2013
// 
// ************************************************************************************
//

#include "UserInput.h"
#include <iostream>
#include <cstring>

using namespace std;



// ------------------------------------------ 
// Prompt for string input
// ------------------------------------------ 
//
// Input:
//   prompt[]   (user prompt string) 
//   fieldVar[] (variable reference to hold the input value)
//   maxChars   (maximum number of characters of input)
//
// Output:
//   fieldVar[] (the input value)
//
void promptForInput(const char prompt[], char fieldVar[], int maxChars)
{

    // Present prompt to the user
    //
    cout << prompt;

    // Get the user input
    //
    cin.get(fieldVar, maxChars, '\n');

    // If an invalid string was entered, prompt for a valid one
    //
    while((!cin) || (strchr(fieldVar, ';')))
    {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << endl
             << ">>> INVALID INPUT >>> (Did you enter a semicolon? Nothing?)"
             << endl
             << prompt;

        cin.get(fieldVar, maxChars, '\n');
    }
    cin.ignore(10000, '\n');

} // end of promptForInput() [strings]



// ------------------------------------------ 
// Prompt for character input
// ------------------------------------------ 
//
// Input:
//   prompt[]   (user prompt string) 
//   fieldVar   (variable reference to hold the input value)
//
// Output:
//   fieldVar   (the input value)
//
void promptForInput(const char prompt[], char& fieldVar)
{

    // Present prompt to the user
    //
    cout << prompt;

    // Get the user input
    //
    cin >> fieldVar;

    // We don't need the rest
    //
    cin.ignore(10000, '\n');

} // end of promptForInput() [char]



// ------------------------------------------ 
// Convert string to lower-case
// ------------------------------------------ 
//
// Input:
//   stringToLower[] (string reference to convert to lower-case)
//
// Output:
//   stringToLower[] (lower-case string)
//
void toLowerString(char stringToLower[])
{

    // Identifiers, defaults
    //
    int maxChars;

    // Maximum number of characters to convert to lower-case
    //
    maxChars = static_cast<int>(strlen(stringToLower));

    // Step through the string and convert each char to lower-case
    //
    for(int loopIdx = 0; loopIdx < maxChars; loopIdx++)
    {
        stringToLower[loopIdx] = tolower(stringToLower[loopIdx]);
    }

} // end of tolowerString()



// ------------------------------------------ 
// Remove whitespace from a string
// ------------------------------------------ 
//
// Input:
//   stringToTrim[]  (string from which whitespace needs to be removed)
//   trimmedString[] (variable reference for the trimmed string)
//
// Output:
//   trimmedString[] (whitespace-free string)
//
void trimString(const char stringToTrim[], char trimmedString[]) 
{

    // Identifiers, defaults
    //
    int  loopIdx;
    int  maxChars;
    char readChar;
    int  arrayCounter = 0;

    // Maximum number of characters to search for whitespace
    //
    maxChars = static_cast<int>(strlen(stringToTrim));

    // Step through the string and only save characters that are not whitespace
    //
    for(loopIdx = 0; loopIdx < maxChars; loopIdx++)
    {
        readChar = stringToTrim[loopIdx];
        if(!isspace(readChar))
        {
            trimmedString[arrayCounter] = readChar;
            arrayCounter++;
        }
    }

    // End the string at the end of input (prevents chars that were not 
    // over-written from appearing in the string)
    //
    trimmedString[arrayCounter] = '\0'; // End the string

} // end of trimString()
 
