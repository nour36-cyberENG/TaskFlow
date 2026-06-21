#include <iostream>
#include <string>
using namespace std;
//name: Nour Abdallah Mohammad Abdo
//c++ project: task Flow 


struct TaskInfo {
    int taskId;
    string taskTitle;
    string description;
    bool completed = false;
};

TaskInfo tasks[100];
//counter to count the number of tasks
int taskCount = 0;

// fun used for another  functions to prevent rewrite some of code
int findIndex(int id) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].taskId == id)
            return i;
    }
    return -1;
}

bool isIdExists(int id) {
    return findIndex(id) != -1;
}
void AddTask() {

    if (taskCount >= 100) {
        cout<< "Task list is full!"<<endl;
        return;
    }

    int newId;

    while (true) {

        try {

            cout<<"Enter task ID: ";
            cin>>newId;

            if (cin.fail()) {
                throw "Invalid Input";
            }

            if (isIdExists(newId)) {
                cout<< "ID " <<newId
                    <<" already exists! Try another."<<endl;
                continue;
            }

            break;
        }
        catch (...) {

            cout<<"Please enter a valid numeric ID." << endl;

            cin.clear();

            string garbage;
            cin>>garbage;
        }
    }

    cin.ignore();

    tasks[taskCount].taskId = newId;

    cout<< "Enter task title: ";
    getline(cin, tasks[taskCount].taskTitle);

    cout<< "Enter description: ";
    getline(cin, tasks[taskCount].description);

    taskCount++;

    cout<<"Task added successfully. (ID: "<<newId << ")"<<endl;
}

void viewTasks() {
	
	//chike if it is empty:
    if (taskCount == 0) {
        cout << "No tasks yet." << endl;
        return;
    }
    cout << "These are all tasks in your TaskFlow program:" << endl;
    for (int i = 0; i < taskCount; i++) {
        cout<< "Task ID: " <<tasks[i].taskId<<endl;
        cout<< "Title: "   <<tasks[i].taskTitle<<endl;
        cout<< "Description: "<<tasks[i].description<<endl;
        cout<< "Status: " << (tasks[i].completed ? "Completed" : "Not Completed") << endl;
        cout<< "-------------------" << endl;
    }
    cout <<"\n+------------------------------+" << endl;

}

void searchTask() {
    int searchId;
    cout<<"Enter the task ID to find: ";
    cin>>searchId;
    
    /*Call findIndex() to search for the task ID
    If the task exists, the function returns its position (index) in the tasks array
     If the task does not exist, it returns -1
    */
    int find = findIndex(searchId);
    if (find != -1) {
        cout << "Task found:" << endl;
        cout << "Task ID: "     << tasks[find].taskId     << endl;
        cout << "Title: "       << tasks[find].taskTitle   << endl;
        cout << "Description: " << tasks[find].description << endl;
        if (tasks[find].completed == true) {
         cout << "Status: Completed" << endl;
        } else {
          cout << "Status: Not Completed" << endl;
        }

    } else {
        cout << "Task not found." << endl;
    }
    cout<<"\n+------------------------------+" << endl;

}

void markTaskCompleted(int id) {
    int i = findIndex(id);
    if (i != -1) {
        tasks[i].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Task not found." << endl;
    }
    cout<<"\n+------------------------------+"<< endl;

}
void showCompletedTasks() {
	
	// If its value has changed: it means there are completed tasks, and if it remains as is, it means there are no completed tasks.
    bool found = false;

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed) {
            cout << "Task ID: " << tasks[i].taskId
                 << " | Title: " << tasks[i].taskTitle << endl;
            found = true;
        }
    }

    if (!found) {
        cout<<"There is no completed task."<<endl;
    }
    cout<<"\n+------------------------------+" << endl;

}

void showPendingTasks(){
	 bool found = false;

    for (int i = 0; i < taskCount; i++) {
        if (!tasks[i].completed) {
            cout << "Task ID: " << tasks[i].taskId
                 << " | Title: " << tasks[i].taskTitle << endl;
            found = true;
        }
    if (!found) {
        cout<<"There is no pending task. all tasks are compeated.What do you think about creating new tasks?"<<endl;
    }
	}
    cout <<"\n+------------------------------+" <<endl;

}
void projectStatistics() {

    int completedCounter = 0;
    int pendingCounter = 0;

    // total tasks
    cout<< "Total number of tasks: "<<taskCount<<endl;

    // completed and pending tasks
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed) {
            completedCounter++;
        } else {
            pendingCounter++;
        }
    }

    cout<< "Total number of completed tasks: "<<completedCounter<<endl;
    cout<< "Total number of pending tasks: "<<pendingCounter<<endl;
    cout<< "\n+------------------------------+"<<endl;

}
int main() {
    int choice;
    do {
          cout << "\n";
        cout << "  +-------------------------------+" << endl;
        cout << "  ¦       TaskFlow System  v1.0   ¦" << endl;
        cout << "  ¦-------------------------------¦" << endl;
        cout << "  ¦  1. Add New Task               ¦" << endl;
        cout << "  ¦  2. View All Tasks             ¦" << endl;
        cout << "  ¦  3. Search Task                ¦" << endl;
        cout << "  ¦  4. Mark Task As Completed     ¦" << endl;
        cout << "  ¦  5. Show Completed Tasks       ¦" << endl;
        cout << "  ¦  6. Show Pending Tasks         ¦" << endl;
        cout << "  ¦  7. Project Statistics         ¦" << endl;
        cout << "  ¦  0. Exit                       ¦" << endl;
        cout << "  +-------------------------------+" << endl;
        cout << "   Enter your choice: ";
        cin >> choice;
        cout <<   "  +------------------------------+" << endl;


        switch (choice) {
            case 1:
                AddTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                searchTask();
                break;
            case 4: {
                int id;
                cout << "Enter task ID to mark as completed: ";
                cin >> id;
                markTaskCompleted(id);
                break;
            }
            case 5:
            	showCompletedTasks();
            	break;
            case 6:
			    showPendingTasks();
				break;	
			case 7:
				projectStatistics();
				break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
