#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task {
    string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << std::endl;
        } else {
            cout << "Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                const Task& task = tasks[i];
                cout << i + 1 << ". " << task.description;
                if (task.completed) {
                    cout << " (Completed)";
                }
                cout <<endl;
            }
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            Task& task = tasks[index - 1];
            task.completed = true;
            cout << "Task marked as completed: " << task.description << endl;
        } else {
            cout << "Invalid task index." <<endl;
        }
    }

    void removeTask() {
        if (tasks.empty()) {
            cout << "No tasks in the list." <<endl;
            return;
        }

        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            const Task& task = tasks[i];
            cout << i + 1 << ". " << task.description;
            if (task.completed) {
                cout << " (Completed)";
            }
            cout <<endl;
        }

        cout << "Enter the index of the task to remove: ";
        size_t index;
        cin >> index;

        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed." << std::endl;
        } else {
            cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        cout << "\n===== To-Do List Manager =====" << std::endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                cin.ignore(); 
                getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                cout << "Enter the index of the task to mark as completed: ";
                size_t index;
                cin >> index;
                toDoList.markTaskAsCompleted(index);
                break;
            }
            case 4:
                toDoList.removeTask();
                break;
            case 5:
                cout << "Exiting the ToDo List Manager. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}