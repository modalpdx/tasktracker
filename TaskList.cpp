//
// ************************************************************************************
// 
// Class:   PCC CS162
// Lab:     5
// Project: Task Tracker - TaskList.cpp
//
// Student: Erik Ratcliffe
// Date   : November 24, 2013
// 
// ************************************************************************************
//

#include "TaskList.h"
#include "UserInput.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;



// Default constructor
//
TaskList::TaskList()
{

    // Set up pointers to the first and last node
    //
    head = NULL;
    tail = head;

    // Initialize the number of tasks
    //
    numTasks = 0;

} // end of TaskList() constructor



// Destructor
//
TaskList::~TaskList()
{
    
    // Delete pointers pointed to by head.
    // Preserve head by using a temporary pointer.
    //
    Node * nextNode;
    nextNode = head;

    // As long as head points to a "next" node...
    //
    while(head != NULL)
    {

        // Move nextNode to the next node after head,
        // delete head, then make head point to
        // nextNode. Lather, rinse, repeat, until
        // head does not point to a "next" node.
        //
        nextNode = head->next;
        delete head;
        head = nextNode;
        tail = head;

    }
    
} // end of ~TaskList() destructor



// ------------------------------------------ 
// Add an entry to the linked list of tasks
// ------------------------------------------ 
//
// Input:
//   task     (new assignment/task)
//
// Output:
//   none
//
void TaskList::addTask(const Task &task)
{

    // Identifiers
    //
    char className[MAX_CHARS_CLASS];
    char assignmentName[MAX_CHARS_ASSIGNMENT];
    char dueDateYear[MAX_CHARS_YEAR];
    char dueDateMonth[MAX_CHARS_MONTH];
    char dueDateDay[MAX_CHARS_DAY];

    char taskClassName[MAX_CHARS_CLASS];           // New task className
    char headNodeClassName[MAX_CHARS_CLASS];       // Head node className
    char tailNodeClassName[MAX_CHARS_CLASS];       // Tail node className
    char innerNodeClassName[MAX_CHARS_CLASS];      // Inner node className
    
    Node * newTask  = new Node;                    // New node to hold the new Task
    Node * nextNode = NULL;                        // Temporary pointer to next node
    Node * prevNode = NULL;                        // Temporary pointer to previous node

    
    // Grab values of identifiers from task...
    //
    task.getClassName(className);
    task.getAssignmentName(assignmentName);
    task.getDueDateYear(dueDateYear);
    task.getDueDateMonth(dueDateMonth);
    task.getDueDateDay(dueDateDay);

    // ...and build the newTask node with task's values
    //
    newTask->data.setClassName(className);
    newTask->data.setAssignmentName(assignmentName);
    newTask->data.setDueDateYear(dueDateYear);
    newTask->data.setDueDateMonth(dueDateMonth);
    newTask->data.setDueDateDay(dueDateDay);
    

    // If we're starting a new list, update head and tail
    // (otherwise they won't point to anything)
    //
    if(numTasks == 0)
    {
        head = newTask;
        tail = newTask;
    }
    else
    {
        // We're not starting a new list. Comparison of nodes is now necessary.
        //
        // First, trim out whitespace from the task's class name and
        // convert to lower case
        //
        trimString(className, taskClassName);
        toLowerString(taskClassName);
        
        // Next, grab and trim out whitespace from the head and tail
        // class names and convert to lower case
        //
        head->data.getClassName(className);
        trimString(className, headNodeClassName);
        toLowerString(headNodeClassName);
        tail->data.getClassName(className);
        trimString(className, tailNodeClassName);
        toLowerString(tailNodeClassName);
        
        if(strcmp(headNodeClassName, taskClassName) > 0)
        {
            // Head class name is GREATER THAN the task class name.
            // Add task to the BEGINNING of the list.
            //
            newTask->next = head;
            head = newTask;
        }
        else if(strcmp(tailNodeClassName, taskClassName) <= 0)
        {
            // Tail class name is LESS THAN OR EQUAL TO the task class name.
            // Add task to the END of the list.
            //
            tail->next = newTask;
            tail = newTask;
        }
        else
        {
            // Task does not go at the beginning or end.
            // Add WITHIN the list.
            //
            for(nextNode = head, prevNode = nextNode; nextNode; prevNode = nextNode, nextNode = nextNode->next)
            {
                // Grab and trim out whitespace from the next node's
                // class names and convert to lower case
                //
                nextNode->data.getClassName(className);
                trimString(className, innerNodeClassName);
                toLowerString(innerNodeClassName);

                // If next node class name is LESS THAN OR EQUAL TO the task
                // class name, continue to the next iteration of the for loop.
                // Otherwise, insert the task BEFORE the next node.
                //
                if(strcmp(innerNodeClassName, taskClassName) <= 0)
                {
                    continue;
                }
                else
                {
                    newTask->next = nextNode;
                    prevNode->next = newTask;
                }
            }
        }
    }
    
    // By now, you've added a task...
    //
    numTasks++;

} // end of addTask()



// ------------------------------------------ 
// Get the number of tasks in the database
// ------------------------------------------ 
//
// Input:
//   none
//
// Output:
//   Return number of tasks currently in the loaded database
//
int TaskList::getNumTasks() const
{

    return numTasks;

} // end of getNumTasks()



// ------------------------------------------ 
// Get an entry from the loaded database
// ------------------------------------------ 
//
// Input:
//   idx      (task list index to process)
//   task     (new assignment/task reference)
//
// Output:
//   task     (update to referenced assignment/task) 
//
// Returns true if the task is found, false otherwise
//
bool TaskList::getTask(int idx, Task& task)
{

    // Identifiers
    //
    char className[MAX_CHARS_CLASS];
    char assignmentName[MAX_CHARS_ASSIGNMENT];
    char dueDateYear[MAX_CHARS_YEAR];
    char dueDateMonth[MAX_CHARS_MONTH];
    char dueDateDay[MAX_CHARS_DAY];

    Node * current; // Temporary pointer to use in place of head
    current = head;

    // Exit w/ false value if the task is not found
    //
    if((idx < 0) || (idx >= numTasks))
    {
        return false;
    }

    // Move to the node indicated by idx
    //
    for(int index = 0; index < idx; index++)
    {
        current = current->next;
    }

    // Read values from the task record, update referenced task
    //
    current->data.getClassName(className);
    current->data.getAssignmentName(assignmentName);
    current->data.getDueDateYear(dueDateYear);
    current->data.getDueDateMonth(dueDateMonth);
    current->data.getDueDateDay(dueDateDay);

    task.setClassName(className);
    task.setAssignmentName(assignmentName);
    task.setDueDateYear(dueDateYear);
    task.setDueDateMonth(dueDateMonth);
    task.setDueDateDay(dueDateDay);

    return true;

} // end of getTask()



// ------------------------------------------ 
// Read the database file
// ------------------------------------------ 
//
// Input:
//   none
//
// Output:
//   none
//
void TaskList::readTaskDatabase()
{

    // Identifiers
    //
    ifstream inFile;
    char className[MAX_CHARS_CLASS];
    char assignmentName[MAX_CHARS_ASSIGNMENT];
    char dueDateYear[MAX_CHARS_YEAR];
    char dueDateMonth[MAX_CHARS_MONTH];
    char dueDateDay[MAX_CHARS_DAY];
    Task task;

    // Open the database file, exit with an error if it fails
    //
    inFile.open(DATABASE_FILE);
    if(!inFile)
    {
        inFile.clear();
        cerr << endl 
             << "*** ERROR: Can not open " 
             << DATABASE_FILE 
             << " for reading! Exiting... ***" 
             << endl;
        exit(1);
    }

    // Get the first field of the next database record, if it exists
    //
    inFile.get(className, MAX_CHARS_CLASS, ';');

    while(!inFile.eof())
    {
      // Read data from the database file
      //
      inFile.get();
      inFile.get(assignmentName, MAX_CHARS_ASSIGNMENT, ';');
      inFile.get();
      inFile.get(dueDateYear, MAX_CHARS_YEAR, ';');
      inFile.get();
      inFile.get(dueDateMonth, MAX_CHARS_MONTH, ';');
      inFile.get();
      inFile.get(dueDateDay, MAX_CHARS_DAY, '\n');
      inFile.ignore(10000, '\n');

      // Copy input to the task object
      //
      task.setClassName(className);
      task.setAssignmentName(assignmentName);
      task.setDueDateYear(dueDateYear);
      task.setDueDateMonth(dueDateMonth);
      task.setDueDateDay(dueDateDay);

      // Add new assignment to database
      //
      addTask(task);

      // Get the first field of the next database record, if it exists
      //
      inFile.get(className, MAX_CHARS_CLASS, ';');
    }

    // Close the file
    //
    inFile.close();

} // end of readTaskDatabase()



// ------------------------------------------ 
// Write the database file
// ------------------------------------------ 
//
// Input:
//   none
//
// Output:
//   none
//
void TaskList::writeTaskDatabase() const
{   

    // Identifiers
    //
    ofstream outFile;
    char className[MAX_CHARS_CLASS];
    char assignmentName[MAX_CHARS_ASSIGNMENT];
    char dueDateYear[MAX_CHARS_YEAR];
    char dueDateMonth[MAX_CHARS_MONTH];
    char dueDateDay[MAX_CHARS_DAY];

    Node * current; // Temporary pointer to use in place of head


    // Open the database file, exit with an error if it fails
    //
    outFile.open(DATABASE_FILE);
    if(!outFile)
    {
        outFile.clear();
        cerr << endl 
             << ">>> Can not open " 
             << DATABASE_FILE 
             << " for writing! Exiting... >>>" 
             << endl;
        exit(1);
    }

    // Step through the linked nodes and extract the data
    // then write it to the outFile
    //
    for(current = head; current; current = current->next)
    {
        current->data.getClassName(className);
        current->data.getAssignmentName(assignmentName);
        current->data.getDueDateYear(dueDateYear);
        current->data.getDueDateMonth(dueDateMonth);
        current->data.getDueDateDay(dueDateDay);

        outFile << className      << ";"
                << assignmentName << ";"
                << dueDateYear    << ";"
                << dueDateMonth   << ";"
                << dueDateDay     << endl;
    }

    // Close the file
    //
    outFile.close();

} // end of writeTaskDatabase()



// ------------------------------------------
// Show heading for task listings
// ------------------------------------------
//
// Input:
//   none
//
// Output:
//   Formatted heading (adjustments to formatting need to also be reflected in showTask())
//
void TaskList::showHeading() const
{
    
    cout << left
        << "Your task list:"
        << endl << endl
        << setw(MAX_CHARS_CLASS)      << "Class Name"
        << setw(MAX_CHARS_ASSIGNMENT) << "Assignment"
        << setw(MAX_CHARS_MONTH + MAX_CHARS_DAY + MAX_CHARS_YEAR) << "Due Date"
        << endl
        << setw(MAX_CHARS_CLASS + MAX_CHARS_ASSIGNMENT + MAX_CHARS_MONTH + MAX_CHARS_DAY + MAX_CHARS_YEAR - 1)
        << setfill('-')
        << "-"
        << setfill(' ')
        << endl;

} // end of showHeading()



// ------------------------------------------
// Show a single task listing
// ------------------------------------------
//
// Input:
//   className       (task class name)
//   assignmentName  (task assignment name)
//   dueDateMonth    (month the task is due)
//   dueDateDay      (day of the month the task is due)
//   dueDateYear     (year the task is due)
//
// Output:
//   Formatted task (adjustments to formatting need to also be reflected in showHeading())
//
void TaskList::showTask(const char className[], const char assignmentName[], const char dueDateMonth[], const char dueDateDay[], const char dueDateYear[]) const
{
    cout << setw(MAX_CHARS_CLASS)
         << className
         << setw(MAX_CHARS_ASSIGNMENT) 
         << assignmentName
         << dueDateMonth << "/"
         << dueDateDay   << "/"
         << dueDateYear
         << endl;

} // end of showTask()



// ------------------------------------------
// List the loaded database
// ------------------------------------------ 
//
// Input:
//   None
//
// Output:
//   None
//
void TaskList::listDatabase() const
{

    // Identifiers
    //
    char className[MAX_CHARS_CLASS];
    char assignmentName[MAX_CHARS_ASSIGNMENT];
    char dueDateYear[MAX_CHARS_YEAR];
    char dueDateMonth[MAX_CHARS_MONTH];
    char dueDateDay[MAX_CHARS_DAY];

    Node * current; // Temporary pointer to use in place of head

    // Display the table header:
    //
    showHeading();

    // ...then, the data itself:
    //
    for(current = head; current; current = current->next)
    {
        current->data.getClassName(className);
        current->data.getAssignmentName(assignmentName);
        current->data.getDueDateYear(dueDateYear);
        current->data.getDueDateMonth(dueDateMonth);
        current->data.getDueDateDay(dueDateDay);
        
        showTask(className, assignmentName, dueDateMonth, dueDateDay, dueDateYear);
    }

} // end of listDatabase()



// ------------------------------------------ 
// Search database for class name
// ------------------------------------------ 
//
// Input:
//   searchString (class name to search for)
//
// Output:
//   None
//
void TaskList::searchDatabase(const char searchString[])
{

    // Identifiers
    //
    char className[MAX_CHARS_CLASS];
    char assignmentName[MAX_CHARS_ASSIGNMENT];
    char dueDateYear[MAX_CHARS_YEAR];
    char dueDateMonth[MAX_CHARS_MONTH];
    char dueDateDay[MAX_CHARS_DAY];

    int  searchResultTasks = 0;
    char tmpClassName[MAX_CHARS_CLASS];
    char trimmedSearchString[MAX_CHARS_CLASS];

    Node * current; // Temporary pointer to use in place of head

    // Trim out whitespace from the class name and convert to lower case
    //
    trimString(searchString, trimmedSearchString);
    toLowerString(trimmedSearchString);

    // Display the table header:
    //
    showHeading();

    // Loop through database entries for records that match the class name
    //
    for(current = head; current; current = current->next)
    {
        // Get the class name from the database record
        //
        current->data.getClassName(className);
        current->data.getAssignmentName(assignmentName);
        current->data.getDueDateYear(dueDateYear);
        current->data.getDueDateMonth(dueDateMonth);
        current->data.getDueDateDay(dueDateDay);

        // Trim out whitespace from the class name 
        // and convert to lower case
        //
        trimString(className, tmpClassName);
        toLowerString(tmpClassName);

        // If the converted search string's class name matches the converted 
        // database class name, display the Task data
        //
        if(!strcmp(trimmedSearchString, tmpClassName))
        {
            showTask(className, assignmentName, dueDateMonth, dueDateDay, dueDateYear);
            
            searchResultTasks++;
        }
    }

    // If nothing was added to the search results, report no results;
    //
    if(searchResultTasks == 0)
    {
        cout << endl
             << ">>> SEARCH CAME UP EMPTY >>>" 
             << endl;
    }

} // end of searchDatabase()

