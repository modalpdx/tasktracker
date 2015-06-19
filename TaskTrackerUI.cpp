//
// ************************************************************************************
// 
// Class:   PCC CS162
// Lab:     5
// Project: Task Tracker - TaskTrackerUI.cpp
//
// Student: Erik Ratcliffe
// Date   : November 24, 2013
// 
// ************************************************************************************
//

#include "TaskList.h"
#include "UserInput.h"
#include "TaskTrackerUI.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;



// ------------------------------------------ 
// Display the menu
// ------------------------------------------ 
//
// Input:
//   None
//
// Output:
//   None
//
void showMenu() 
{

    cout << endl
         << "Main menu:"
         << endl << endl
         << "\t L -> List all tasks"
         << endl
         << "\t N -> Enter a new task"
         << endl
         << "\t S -> Search tasks"
         << endl
         << "\t Q -> Quit"
         << endl << endl;

} // end of showMenu()



// ------------------------------------------ 
// Get the menu selection
// ------------------------------------------ 
//
// Input:
//   None
//
// Output: 
//   sel (returned lower-case menu selection)
//
char getMenuSelection()
{

    // Identifiers
    //
    char sel;

    // Prompt for a menu choice
    //
    promptForInput("Please enter your choice: ", sel);

    // Convert to lower-case
    //
    sel = tolower(sel);

    // If the menu choice is not valid...
    //
    while(!strchr(ALLOWED_MENU_CHOICES, sel))
    {
        cout << "Please enter a valid choice: ";
        cin >> sel;
        cin.ignore(10000, '\n');
    }

    // Return the valid menu choice
    //
    return sel;

} // end of getMenuSelection()



// ------------------------------------------ 
// Execute menu action
// ------------------------------------------ 
//
// Input: 
//   sel    (lower-case menu selection)
//   tasks  (reference to assignment/task database) 
//
// Output:
//   tasks  (assignment/task database) 
//
void doMenuAction(char sel, TaskList& tasks)
{

    // Identifiers
    //
    char className[MAX_CHARS_CLASS];
    Task task;

    cout << endl;

    // Execute the action associated with the menu choice
    // (Q for quit is handled in main())
    //
    switch(sel)
    {
        case 'l':
            tasks.listDatabase();            // List the database
            break;
        case 's':
            promptForInput("Enter a class to search for: ", className, MAX_CHARS_CLASS);
            tasks.searchDatabase(className); // Search database for class name
            break;
        case 'n':
            readTask(task);                  // Read in a new assignment entry
            tasks.addTask(task);             // Add new assignment to database
            break;
        default:
            break;
    }

} // end of doMenuAction()



// ------------------------------------------ 
// Read in a new assignment entry
// ------------------------------------------ 
//
// Input:
//   task  (variable reference to hold new assignment/task) 
//
// Output:
//   task  (new assignment/task) 
//
void readTask(Task& task) 
{

    // Identifiers
    //
    char className[MAX_CHARS_CLASS];
    char assignmentName[MAX_CHARS_ASSIGNMENT];
    char dueDateYear[MAX_CHARS_YEAR];
    char dueDateMonth[MAX_CHARS_MONTH];
    char dueDateDay[MAX_CHARS_DAY];

    cout << "Follow the prompts. Semicolons are not allowed."
         << endl;

    // Prompt for assignment/task fields
    //
    promptForInput("Enter your class (ex: \"CS 162\"): ", className, MAX_CHARS_CLASS);
    promptForInput("Enter your assignment (ex: \"Read chapter 12\"): ", assignmentName, MAX_CHARS_ASSIGNMENT);
    promptForInput("Enter a 4-digit year (ex: \"2013\"): ", dueDateYear, MAX_CHARS_YEAR);
    promptForInput("Enter a numeric month (ex: \"10\" for October): ", dueDateMonth, MAX_CHARS_MONTH);
    promptForInput("Enter a numeric day (ex: \"07\" for the 7th): ", dueDateDay, MAX_CHARS_DAY);

    // Copy input to the task object
    //
    task.setClassName(className);
    task.setAssignmentName(assignmentName);
    task.setDueDateYear(dueDateYear);
    task.setDueDateMonth(dueDateMonth);
    task.setDueDateDay(dueDateDay);

} // end of readTask()

