//
// ************************************************************************************
// 
// Class:   PCC CS162
// Lab:     5
// Project: Task Tracker - Task.h
//
// Student: Erik Ratcliffe
// Date   : November 24, 2013
// 
// ************************************************************************************
//

#ifndef TASK_H
#define TASK_H


const int  MAX_CHARS_CLASS         = 21;
const int  MAX_CHARS_ASSIGNMENT    = 51;
const int  MAX_CHARS_YEAR          = 5;
const int  MAX_CHARS_MONTH         = 3;
const int  MAX_CHARS_DAY           = 3;


// Task class
// --------------------------------------
//
// Holds a description of a classroom assignment or task
// and a date when it is due or when it will occur
//
// Members include:
//
//    Class or course name
//    Assignment or task name
//    Year/Month/Day when the assignment or task is due or will occur
//
class Task {

    public: 

        // Constructors
        //
        Task();
        Task(const char className[], const char assignmentName[], const char dueDateYear[], const char dueDateMonth[], const char dueDateDay[]);
    
        // Destructor
        //
        ~Task();

        // Accessor functions
        //
        // Get private variable values
        //
        void getClassName(char className[]) const;
        void getAssignmentName(char assignmentName[]) const;
        void getDueDateYear(char dueDateYear[]) const;
        void getDueDateMonth(char dueDateMonth[]) const;
        void getDueDateDay(char dueDateDay[]) const;

        // Mutator functions
        //
        // Set private variable values
        //
        void setClassName(const char className[]);
        void setAssignmentName(const char assignmentName[]);
        void setDueDateYear(const char dueDateYear[]);
        void setDueDateMonth(const char dueDateMonth[]);
        void setDueDateDay(const char dueDateDay[]);

    private:

        // Data members
        //
        char * className;
        char * assignmentName;
        char * dueDateYear;
        char * dueDateMonth;
        char * dueDateDay;

};


#endif

