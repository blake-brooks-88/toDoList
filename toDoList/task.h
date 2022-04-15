#pragma once
#include <string>
#include <vector>

class Task
{

// methods start ======================
public:
	Task(std::string name = "New Task",
		std::string description = "New Description",
		std::vector<Task> subTasks = {},
		int status = 0,
		int parentID = -1);
	~Task();
private:
	void updateName();
	std::string getNameFromUser();
	int generateNewID();
	int getLastIDFromFile(std::string filePath);
	void updateLastID(int newID, std::string filePath);

// methods end ======================

// members start ======================
public:
	int ID;

	int parentID;
	std::string name;
	std::string description;
	std::vector<Task> subTasks;
	int status;
	enum class StatusCode { NOT_STARTED, IN_PROGRESS, COMPLETE };
	std::string ID_FILE_PATH = "lastID.txt";
private:
// members end ======================


};

