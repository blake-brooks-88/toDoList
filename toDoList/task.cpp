#include "task.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

Task::Task(std::string name, std::string description, std::vector<Task> subTasks, int status, int parentID)
{
	this->ID = Task::generateNewID();
	this->name = name;
	this->description = description;
	this->subTasks = subTasks;
	this->status = status;
	this->parentID = parentID;
}

Task::~Task()
{

}

void Task::updateName()
{
	this->name = getNameFromUser();
}

std::string Task::getNameFromUser()
{
	std::string response{};
	std::cout << "Task Name: ";
	std::cin >> response;

	return response;
}

int Task::generateNewID()
{
	//initializeFile()
	int lastID = getLastIDFromFile(this->ID_FILE_PATH);
	int newID = lastID + 1;
	updateLastID(newID, this->ID_FILE_PATH);

	return newID;
}

 int Task::getLastIDFromFile(std::string filePath)
{
	std::ifstream rFile;
	rFile.open(filePath);

	std::string ID;
	std::getline(rFile, ID);
	rFile.close();

	return std::stoi(ID);
}

void Task::updateLastID(int newID, std::string filePath)
{
	std::ofstream wFile;
	wFile.open(filePath);

	wFile << newID;
	wFile.close();
}

// CSV File Reader
// Create an array of all tasks
// Create an array of all sub tasks
// Loop through the task array
	// For each task, loop through all of the sub tasks
	// If a sub-task's parent ID matches the ID of the current task 
		// Add that task to the current task's sub-task array
		// Pop that task out of the sub task array