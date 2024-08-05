#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string taskName;  // Name of the task
    bool isCompleted; // Completion status of the task
};

// Vector to store the list of tasks
vector<Task> taskList;

// Function to add a new task to the list
void addNewTask() {
    string name;
    cout << "Enter the name of the new task: ";
    getline(cin, name);
    taskList.push_back({name, false});
    cout << "Task successfully added!" << endl;
}

// Function to display all tasks in the list
void showTasks() {
    cout << "Current Task List:" << endl;
    if (taskList.empty()) {
        cout << "The task list is currently empty." << endl;
    } else {
        for (int index = 0; index < taskList.size(); index++) {
            cout << index + 1 << ". [" << (taskList[index].isCompleted ? "X" : " ") << "] " << taskList[index].taskName << endl;
        }
    }
}

// Function to mark a specific task as completed
void completeTask() {
    if (taskList.empty()) {
        cout << "The task list is empty. No tasks to mark as completed." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the number of the task you want to mark as completed: ";
    cin >> taskNumber;
    cin.ignore(); // Ignore the newline character
    if (taskNumber > 0 && taskNumber <= taskList.size()) {
        taskList[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number. Please enter a number between 1 and " << taskList.size() << "." << endl;
    }
}

// Function to remove a specific task from the list
void deleteTask() {
    if (taskList.empty()) {
        cout << "The task list is empty. No tasks to remove." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the number of the task you want to remove: ";
    cin >> taskNumber;
    cin.ignore(); // Ignore the newline character
    if (taskNumber > 0 && taskNumber <= taskList.size()) {
        taskList.erase(taskList.begin() + taskNumber - 1);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task number. Please enter a number between 1 and " << taskList.size() << "." << endl;
    }
}

// Main function to control the program flow
int main() {
    int userChoice;
    while (true) {
        cout << "\n=== Task List Manager ===" << endl;
        cout << "1. Add a new task" << endl;
        cout << "2. View the current tasks" << endl;
        cout << "3. Mark a task as completed" << endl;
        cout << "4. Remove a task" << endl;
        cout << "5. Exit the program" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> userChoice;
        cin.ignore(); // Ignore the newline character

        switch (userChoice) {
            case 1:
                addNewTask();
                break;
            case 2:
                showTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    }
}
