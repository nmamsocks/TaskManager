
#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string name;      
    std::string description;
    // If task is completed it will equal true, if not it will be false
    bool isDone;

public:
    // Create task with name and description and mark it uncompleted
    Task(const std::string& taskName, const std::string& taskDescription) {
        name = taskName;
        description = taskDescription;
        isDone = false;
    }

    // Mark task as done
    void markDone() {
        isDone = true;
    }

    // Display task details and description and if its finished or not
    void display(int index) const {
        // Simple display of task details
        std::cout << index + 1 << ". " << name << " [" << (isDone ? "Done" : "Pending") << "]\n";
        std::cout << "   Description: " << description << "\n";
    }

    // Check if the task is done
    bool getStatus() const {
        return isDone;
    }

    // Get task name
    std::string getName() const {
        return name;
    }
};

class TaskManager {
private:
    // List of tasks to compelete
    std::vector<Task> taskList; 
    int points;                

public:
    TaskManager() {
        points = 0; 
    }

    // Add a new task to the list
    void addTask(const std::string& name, const std::string& description) {
        taskList.push_back(Task(name, description)); 
        std::cout << "Task \"" << name << "\"!\n";
    }

    // View all tasks
    void viewTasks() const {
        if (taskList.size() == 0) { 
            std::cout << "No tasks!\n";
            return;
        }

        std::cout << "Task List \n";
        for (int i = 0; i < taskList.size(); i++) { 
            taskList[i].display(i);
        }
        std::cout << "-----------------\n";
    }

    // Remove a task by index
    void removeTask(int index) {
        if (index < 1 || index > taskList.size()) {
            std::cout << "Task doesnt exist! Try again.\n";
            return;
        }
        std::cout << "Task \"" << taskList[index - 1].getName() << "\" removed.\n";
        taskList.erase(taskList.begin() + (index - 1));
    }

    // Mark a task as done
    void markTaskDone(int index) {
        if (index < 1 || index > taskList.size()) {
            std::cout << "Invalid number!\n";
            return;
        }
        if (!taskList[index - 1].getStatus()) {
            taskList[index - 1].markDone();
            // Reward for compeleting (in future make it random or based off difficulty) 
            points += 10; 
            std::cout << "Task \"" << taskList[index - 1].getName() << "\" done! +10 points \n";
        }
        else {
            std::cout << "Task is already finished!\n";
        }
    }

    // Display  points
    void displayPoints() const {
        std::cout << "Points: " << points << "\n";
    }
};

// Display menu options
void displayMenu() {
    std::cout << "\nTask Manager \n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Remove Task\n";
    std::cout << "4. Mark Task as Done\n";
    std::cout << "5. View Points\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    TaskManager manager;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;
        // Used to make sure next line is ready
        std::cin.ignore(); 

        if (choice == 1) {
            // Add a task
            std::string name, description;
            std::cout << "Enter task name: "; 
            std::getline(std::cin, name);
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);
            manager.addTask(name, description);
        }
        else if (choice == 2) {
            // Viewing tasks
            manager.viewTasks();
        }
        else if (choice == 3) {
            // Remove task
            int taskNumber;
            manager.viewTasks();
            std::cout << "Enter task number to remove: ";
            std::cin >> taskNumber;
            manager.removeTask(taskNumber);
        }
        else if (choice == 4) {
            // Marking a task done
            int taskNumber;
            manager.viewTasks();
            std::cout << "Enter task number to mark as done: ";
            std::cin >> taskNumber;
            manager.markTaskDone(taskNumber);
        }
        else if (choice == 5) {
            // Viewing points
            manager.displayPoints();
        }
        else if (choice == 6) {
            // Exiting the program
            std::cout << "Exiting!\n";
            break;
        }
        else {
            // Invalid choice
            std::cout << "Try again.\n";
        }
    }

    return 0;
}

