//
// ************************************************************************************
// 
// Class:   PCC CS162
// Lab:     5
// Project: Task Tracker
//
// Student: Erik Ratcliffe
// Date   : November 24, 2013
// 
// ************************************************************************************
//

// Visual Studio memory leak detection items
/*
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
*/

// TaskTracker headers
#include "TaskList.h"
#include "TaskTrackerUI.h"
#include <iostream>

using namespace std;


// Constants
//
const char APP_VERSION[] = "0.04";



// ------------------------------------------------------------------------------------ 
// 
// Main function
// 
// ------------------------------------------------------------------------------------
//

int main()
{

	// Enable Visual Studio memory leak detection
	//
	//_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    // Identifiers, defaults
    //
    TaskList tasks;       // In-memory task database
    //int  numTasks = 0;  // Holds the size of the task database array
    char selection;       // Selected menu item

    // Say who we are...
    //
    cout << endl
         << "TASK TRACKER v" << APP_VERSION 
         << endl;

    // Read assignments from the database
    //
    tasks.readTaskDatabase();

    // Offer the menu until the user quits
    //
    showMenu();
    selection = getMenuSelection();

    while(selection != 'q')
    {
        doMenuAction(selection, tasks);
        showMenu();
        selection = getMenuSelection();
    }

    // Write assignment entries to the database
    //
    tasks.writeTaskDatabase();

    return 0;

} // end of main()

