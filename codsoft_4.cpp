/*TASK 4
TO-DO LIST
Build a simple console-based to-do list manager that allows users to add, view, and delete tasks

Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list

Coded by Ashwath Gupta 
Version 1.0 
Date: 25 August 2024
*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

void addTask(vector<Task>& tasks) {
    cout << "Enter task description: ";
    string description;
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "Your tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << "\n";
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed.\n";
        return;
    }
    cout << "Enter task number to mark as completed: ";
    int taskNum;
    cin >> taskNum;
    cin.ignore(); 
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to remove.\n";
        return;
    }
    cout << "Enter task number to remove: ";
    int taskNum;
    cin >> taskNum;
    cin.ignore(); 
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void userMenu(vector<Task>& tasks) {
    int choice;

    do {
        cout << "\nTO-DO LIST MANAGER\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Log Out\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    unordered_map<string, vector<Task>> users;
    string username;

    while (true) {
        cout << "\nTO-DO LIST MANAGER\n";
        cout << "1. Log In\n";
        cout << "2. Create New Account\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                getline(cin, username);
                if (users.find(username) != users.end()) {
                    userMenu(users[username]);
                } else {
                    cout << "User not found. Please create a new account.\n";
                }
                break;
            case 2:
                cout << "Enter new username: ";
                getline(cin, username);
                if (users.find(username) == users.end()) {
                    users[username] = vector<Task>();
                    cout << "Account created successfully!\n";
                } else {
                    cout << "Username already exists. Please choose a different username.\n";
                }
                break;
            case 3:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
