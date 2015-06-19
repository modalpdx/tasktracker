# "Task Tracker"
A school project for a flat-file database that tracks homework
assignments.

##How the program works:

A file called tasks.txt holds class/homework/date information. It is
opened when the program starts, and its content is read into memory. 

The user is prompted with a menu of four options: list all tasks, enter a
new task, search tasks, or quit. The search functionality is fuzzy, so
searching for "CS162", "c S16 2", and "C s    1  62" will all produce the
same results. There is a limit on input string length so if too many
spaces are added, the search string will not include all characters.

There is no delete functionality in this program.

This program was primarily an exercise in basic filesystem I/O and linked
lists.

##Build:

Download everything and run "make." A sample tasks.txt file is included so
the program will have something to show when it's first executed.

##Colophon:

This program was written 100% in C++ with standards in mind. It has been
built and tested on Linux, Mac OS, and Windows. The code was written to
compile in Visual Studio, but GCC and LLVM do not seem to have any issues
with it.

##Disclaimer:

This is code from a school project. It satisfies assignment requirements
but is nowhere near as "scrubbed" as released software should be.
Security is not addressed, only functionality and no input validation. The
assignment scope was limited so there are bound to be issues and quirks.

If you use this code for anything other than satisfying your curiosity,
please keep the following in mind:

- there is no warranty of any kind (you use the code as-is)
- there is no support offered, please do not ask
- there is no guarantee it'll work, although it's not complex so it should
  work
- please do not take credit for code you did not write, especially if you
  are a student. NO CHEATING.

Thanks!
