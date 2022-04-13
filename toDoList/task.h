#pragma once
#include <string>
#include <vector>

class Task
{

// methods start ======================
public:
	Task(
		std::string name,
		std::string description,
		std::vector<Task> subTasks,
		int status = 0
	);

private:

// methods end ======================

// members start ======================
public:

private:
	std::string name;
	std::string description;
	std::vector<Task> subTasks;
	int status;
	const enum class StatusCode { NOT_STARTED, IN_PROGRESS, COMPLETE };
// members end ======================


};

