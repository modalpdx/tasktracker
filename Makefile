all: task_tracker

task_tracker: Task.o TaskList.o TaskTrackerUI.o UserInput.o task_tracker.o
	g++ Task.o TaskList.o TaskTrackerUI.o UserInput.o task_tracker.o -o task_tracker

Task.o: Task.cpp
	g++ -c Task.cpp

TaskList.o: TaskList.cpp
	g++ -c TaskList.cpp

TaskTrackerUI.o: TaskTrackerUI.cpp
	g++ -c TaskTrackerUI.cpp

UserInput.o: UserInput.cpp
	g++ -c UserInput.cpp

task_tracker.o: task_tracker.cpp
	g++ -c task_tracker.cpp

clean:
	rm -rf *o task_tracker

