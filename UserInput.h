//
// ************************************************************************************
// 
// Class:   PCC CS162
// Lab:     5
// Project: Task Tracker - UserInput.h
//
// Student: Erik Ratcliffe
// Date   : November 24, 2013
// 
// ************************************************************************************
//

#ifndef USER_INPUT_H
#define USER_INPUT_H


// Function prototypes
//
void promptForInput(const char prompt[], char fieldVar[], int maxChars); // Prompt for string
void promptForInput(const char prompt[], char& fieldVar);                // Prompt for char
void toLowerString(char stringToLower[]);                                // Convert to lower case
void trimString(const char stringToTrim[], char trimmedString[]);        // Trim whitespace


#endif
