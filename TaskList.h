//
// ************************************************************************************
// 
// Class:   PCC CS162
// Lab:     5
// Project: Task Tracker - TaskList.h
//
// Student: Erik Ratcliffe
// Date   : November 24, 2013
// 
// ************************************************************************************
//

#ifndef TASK_LIST_H
#define TASK_LIST_H


#include <cstring> // for NULL
#include "Task.h"


const int  MAX_TASKS       = 100;
const char DATABASE_FILE[] = "tasks.txt";



// TaskList class
// --------------------------------------
//
// Holds a linked list of Task class objects
//
// Members include:
//
//    Linked list of Task objects
//    Number of Task objects in the database
//
class TaskList {

    public:

        // Constructor
        //
        TaskList();
    
        // Destructor
        //
        ~TaskList();

        // Accessor functions
        //
        void writeTaskDatabase() const;                 // Write database to the DATABASE_FILE
        int  getNumTasks() const;                       // Get number of loaded tasks
        void listDatabase() const;                      // List all tasks
        void showHeading() const;                       // Show the heading for task listings
        void showTask(const char className[], const char assignmentName[], const char dueDateMonth[], const char dueDateDay[], const char dueDateYear[]) const;
                                                        // Show a single task listing
        
        // Mutator functions
        //
        void readTaskDatabase();                        // Read task database from the DATABASE_FILE
        void searchDatabase(const char searchString[]); // Search, list results
        void addTask(const Task &task);                 // Add a new task
        bool getTask(int idx, Task& task);              // Grab a single task

    private:

        // Linked list node
        //
        struct Node
        {

            Task   data;
            Node * next;

            // Constructor
            //
            Node()
            {
                next = NULL;
            }

        };

        // Data members
        //
        Node * head;         // Pointer to first node in linked list
        Node * tail;         // Pointer to last node in linked list
        int    numTasks;     // Number of loaded tasks

};


#endif
