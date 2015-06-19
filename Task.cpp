//
// ************************************************************************************
// 
// Class:   PCC CS162
// Lab:     5
// Project: Task Tracker - Task.cpp
//
// Student: Erik Ratcliffe
// Date   : November 24, 2013
// 
// ************************************************************************************
//

#include "Task.h" 
#include <iostream>
#include <cstring>

using namespace std;



// Default constructor
//
Task::Task() 
{

    // Set up pointers to each Task field, sized to fit snugly
    //
    className = new char[strlen("No Class") + 1];
    strcpy(className, "No Class");
    
    assignmentName = new char[strlen("No Assignment") + 1];
    strcpy(assignmentName, "No Assignment");
    
    dueDateYear = new char[strlen("xxxx") + 1];
    strcpy(dueDateYear, "xxxx");
    
    dueDateMonth = new char[strlen("xx") + 1];
    strcpy(dueDateMonth, "xx");
    
    dueDateDay = new char[strlen("xx") + 1];
    strcpy(dueDateDay, "xx");

} // end of Task() default constructor



// Alternate constructor
//
Task::Task(const char className[], const char assignmentName[], const char dueDateYear[], const char dueDateMonth[], const char dueDateDay[]) 
{

    // Set up pointers to each Task field, sized to fit snugly
    //
    this->className = new char[strlen(className) + 1];
    strcpy(this->className, className);
    
    this->assignmentName = new char[strlen(assignmentName) + 1];
    strcpy(this->assignmentName, assignmentName);
    
    this->dueDateYear = new char[strlen(dueDateYear) + 1];
    strcpy(this->dueDateYear, dueDateYear);
    
    this->dueDateMonth = new char[strlen(dueDateMonth) + 1];
    strcpy(this->dueDateMonth, dueDateMonth);
    
    this->dueDateDay = new char[strlen(dueDateDay) + 1];
    strcpy(this->dueDateDay, dueDateDay);

} // end of Task() alternate constructor



// Destructor
//
Task::~Task()
{
    
    // If data members contains data, delete the memory
    // pointed to by the pointer
    //
    if(className != NULL)      delete [] className;
    if(assignmentName != NULL) delete [] assignmentName;
    if(dueDateYear != NULL)    delete [] dueDateYear;
    if(dueDateMonth != NULL)   delete [] dueDateMonth;
    if(dueDateDay != NULL)     delete [] dueDateDay;
    
} // end of ~Task() destructor



// ------------------------------------------
// Get the value of the private className var
// ------------------------------------------ 
//
// Input:
//   className (var to hold class name)
//
// Output:
//   className (class name)
//
void Task::getClassName(char className[]) const
{

    strcpy(className, this->className);

} // end of getClassName()



// ----------------------------------------------- 
// Get the value of the private assignmentName var
// ----------------------------------------------- 
//
// Input:
//   assignmentName (var to hold assignment name)
//
// Output:
//   assignmentName (assignment name)
//
void Task::getAssignmentName(char assignmentName[]) const
{

    strcpy(assignmentName, this->assignmentName);

} // end of getAssignmentName()



// --------------------------------------------
// Get the value of the private dueDateYear var
// -------------------------------------------- 
//
// Input:
//   dueDateYear (var to hold the year of the assignment)
//
// Output:
//   dueDateYear (year of the assignment/task due date)
//
void Task::getDueDateYear(char dueDateYear[]) const
{

    strcpy(dueDateYear, this->dueDateYear);

} // end of getDueDateyear()



// --------------------------------------------- 
// Get the value of the private dueDateMonth var
// --------------------------------------------- 
//
// Input:
//   dueDateMonth (var to hold the month of the assignment)
//
// Output:
//   dueDateMonth (month of the assignment/task due date)
//
void Task::getDueDateMonth(char dueDateMonth[]) const
{

    strcpy(dueDateMonth, this->dueDateMonth);

} // end of getDueDateMonth()



// ------------------------------------------- 
// Get the value of the private dueDateDay var
// ------------------------------------------- 
//
// Input:
//   dueDateDay (var to hold the day of the assignment)
//
// Output:
//   dueDateDay (day of the assignment/task due date)
//
void Task::getDueDateDay(char dueDateDay[]) const
{

    strcpy(dueDateDay, this->dueDateDay);

} // end of getDueDateDay()



// ------------------------------------------ 
// Set the value of the private className var
// ------------------------------------------ 
//
// Input:
//   className (new class name)
//
// Output:
//   none
//
void Task::setClassName(const char className[])
{

    // Clear memory occupied by the className data member
    //
    if(this->className != NULL) delete [] this->className;
    
    // Set up a new pointer to the className data member,
    // sized to fit snugly
    //
    this->className = new char[strlen(className) + 1];
    strcpy(this->className, className);

} // end of setClassName()



// ----------------------------------------------- 
// Set the value of the private assignmentName var
// ----------------------------------------------- 
//
// Input:
//   assignmentName (new assignment name)
//
// Output:
//   none
//
void Task::setAssignmentName(const char assignmentName[])
{
    
    // Clear memory occupied by the assignmentName data member
    //
    if(this->assignmentName != NULL) delete [] this->assignmentName;
    
    // Set up a new pointer to the assignmentName data member,
    // sized to fit snugly
    //
    this->assignmentName = new char[strlen(assignmentName) + 1];
    strcpy(this->assignmentName, assignmentName);

} // end of setAssignmentName()



// -------------------------------------------- 
// Set the value of the private dueDateYear var
// -------------------------------------------- 
//
// Input:
//   dueDateYear (year of the new assignment/task due date)
//
// Output:
//   none
//
void Task::setDueDateYear(const char dueDateYear[])
{
    
    // Clear memory occupied by the dueDateYear data member
    //
    if(this->dueDateYear != NULL) delete [] this->dueDateYear;
    
    // Set up a new pointer to the dueDateYear data member,
    // sized to fit snugly
    //
    this->dueDateYear = new char[strlen(dueDateYear) + 1];
    strcpy(this->dueDateYear, dueDateYear);

} // end of setDueDateyear()



// --------------------------------------------- 
// Set the value of the private dueDateMonth var
// --------------------------------------------- 
//
// Input:
//   dueDateMonth (month of the new assignment/task due date)
//
// Output:
//   none
//
void Task::setDueDateMonth(const char dueDateMonth[])
{
    
    // Clear memory occupied by the dueDateMonth data member
    //
    if(this->dueDateMonth != NULL) delete [] this->dueDateMonth;
    
    // Set up a new pointer to the dueDateMonth data member,
    // sized to fit snugly
    //
    this->dueDateMonth = new char[strlen(dueDateMonth) + 1];
    strcpy(this->dueDateMonth, dueDateMonth);

} // end of setDueDateMonth()



// ------------------------------------------- 
// Set the value of the private dueDateDay var
// ------------------------------------------- 
//
// Input:
//   dueDateDay (day of the new assignment/task due date)
//
// Output:
//   none
//
void Task::setDueDateDay(const char dueDateDay[])
{
    
    // Clear memory occupied by the dueDateDay data member
    //
    if(this->dueDateDay != NULL) delete [] this->dueDateDay;
    
    // Set up a new pointer to the dueDateDay data member,
    // sized to fit snugly
    //
    this->dueDateDay = new char[strlen(dueDateDay) + 1];
    strcpy(this->dueDateDay, dueDateDay);

} // end of setDueDateDay()

