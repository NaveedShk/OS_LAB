#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <sys/wait.h>

using namespace std;

void displayUserID() {
    cout << "User ID: " << getuid() << endl;
}

int main() {
    pid_t processID = fork();

    if (processID < 0) {
        cout << "Fork failed. Process ID: " << getpid() << endl;
    } 
    else if (processID == 0) { 
        cout << "Child Process ID: " << getpid() << endl;
        cout << "Parent Process ID (from Child Process): " << getppid() << endl;
        cout << "Displaying User ID from Child Process: ";
        displayUserID();
        exit(0);
    } 
    else { 
        wait(NULL);  
        cout << "Parent Process ID: " << getpid() << endl;
        displayUserID();
    }

    return 0;
}
