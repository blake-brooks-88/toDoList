#include <iostream>
#include <fstream>
#include <vector>
#include "fileManager.h"

FileManager::FileManager(std::string filePath)
{
	this->filePath = filePath;
}

void FileManager::addTaskToFile(Task task)
{
	std::ofstream wFile;
	wFile.open(this->filePath, std::ios_base::app);

	wFile <<
		task.ID << "," <<
		task.name << "," <<
		task.description << "," <<
		task.status << "," <<
		task.parentID << std::endl;
}

void FileManager::addTasksToFile(std::vector<Task> tasks)
{
	for (Task task : tasks)
	{
		addTaskToFile(task);
	}
}