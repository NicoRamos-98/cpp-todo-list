#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

struct Task {
    string description;
    bool completed = false;
};

void showMenu() {
    cout << "\n===== To-Do List =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Done\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void addTask(Task tasks[], int& taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full!\n";
        return;
    }

    cin.ignore(); // clear buffer before getline
    cout << "Enter task description: ";
    getline(cin, tasks[taskCount].description);
    tasks[taskCount].completed = false;
    taskCount++;

    cout << "Task added!\n";
}

void viewTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks yet.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) cout << " [✔️]";
        cout << endl;
    }
}

void markTaskDone(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks to mark as done!\n";
        return;
    }

    int index;
    cout << "Enter task number to mark as done: ";
    cin >> index;

    if (index > 0 && index <= taskCount) {
        tasks[index - 1].completed = true;
        cout << "Marked as done!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
     Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markTaskDone(tasks, taskCount);
                break;
            case 4:
                cout << "Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}