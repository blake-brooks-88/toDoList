#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "task.h"

class FileManager
{
public:
	FileManager(std::string filePath);
	void addTaskToFile(Task task);
	void addTasksToFile(std::vector<Task> tasks);

private:
	std::string filePath;

};