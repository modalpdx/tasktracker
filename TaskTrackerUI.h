//
// ************************************************************************************
// 
// Class:   PCC CS162
// Lab:     5
// Project: Task Tracker - TaskTrackerUI.h
//
// Student: Erik Ratcliffe
// Date   : November 24, 2013
// 
// ************************************************************************************
//

#ifndef TASK_TRACKER_UI_H
#define TASK_TRACKER_UI_H


const char ALLOWED_MENU_CHOICES[]  = "lnsq"; // Always include q for quit!

// Function prototypes
//
void showMenu();                              // Display the menu
void readTask(Task& task);                    // Get fields of a Task record
char getMenuSelection();                      // Get the user's menu selection
void doMenuAction(char sel, TaskList& tasks); // Perform the selected menu action


#endif
