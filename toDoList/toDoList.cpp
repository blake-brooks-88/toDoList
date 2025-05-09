#include <iostream>
#include "task.h"
#include "fileManager.h"
#include <vector>

void displayMainMenu();
void validateUserInput(int& response, int numberOfOptions);
void run();

const std::string FILE_PATH = "toDoList.csv";

int main()
{
	//run();
	std::string name = "Task 1";
	std::string description = "This is just a test tast";
	std::vector<Task> subTasks{};
	Task firstTask(name, description, subTasks);
	Task secondTask;
	Task thirdTask(description, name);

	std::vector<Task> tasks{ firstTask, secondTask, thirdTask };

	FileManager fManager(FILE_PATH);

	fManager.addTasksToFile(tasks);
}

void run()
{
	bool isRunning = true;

	int response{ 0 };
	int numberOfMenuItems{ 4 };
	std::cin.clear();

	while (isRunning)
	{
		displayMainMenu();
		std::cin >> response;

		validateUserInput(response, numberOfMenuItems);

		switch (response)
		{
		case 1:
			//create new todo list
			break;
		case 2:
			//load todo list from file
		case 3:
			// save current todo list to file
		case 4:
			isRunning = false;
		default:
			break;
		}
	}
}

void displayMainMenu()
{
	
	std::cout << "Welcome to the To Do List Program. What would you like to do?\n";

	std::cout
		<< "1. Create a new To Do List\n"
		<< "2. Load a To Do List\n"
		<< "3. Save Current To Do List\n"
		<< "4. Exit Program!\n";
	
}

void validateUserInput(int& response, int numberOfOptions)
{
	while (!std::cin.good() || response < 1 || response > numberOfOptions)
	{
		std::cout << "Error, please select a number between " << 1 << " and " << numberOfOptions << ": ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> response;
	}
}