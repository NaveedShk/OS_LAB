#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t processID = fork();

    if (processID < 0) {
        cerr << "Failed to create child process. Current Process ID: " << getpid() << endl;
        return 1;
    } 
    else if (processID == 0) { 
        cout << "Child process initiated. Process ID: " << getpid() << endl;
    
        if (execlp("ls", "ls", NULL) == -1) {
            perror("Execution of ls command failed");
            exit(1);
        }
    } 
    else { 
        wait(NULL);  
        cout << "Parent process resuming. Process ID: " << getpid() << endl;
    }

    return 0;
}
