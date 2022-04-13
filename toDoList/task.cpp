#include "task.h"
#include <string>
#include <vector>

Task::Task(std::string name = "New Task",
	std::string description = "New Description",
	std::vector<Task> subTasks = {},
	int status = 0)
{
	this->name = name;
	this->description = description;
	this->subTasks = subTasks;
	this->status = status;
}