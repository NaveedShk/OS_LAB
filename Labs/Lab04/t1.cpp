#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t child1, child2;
    
    cout << "Main process ID: " << getpid() << endl;
    child1 = fork(); 

    if (child1 == 0) {
        // First spawned process displays its ID
        cout << "First child executing (PID: " << getpid() << ")" << endl;
        cout << "First child process exiting..." << endl;
        exit(0);
    } 
    
    child2 = fork();  

    if (child2 == 0) {
        // Second spawned process displays its ID
        cout << "Second child executing (PID: " << getpid() << ")" << endl;
        cout << "Second child process exiting..." << endl;
        exit(0);
    }

    cout << "Main process is waiting for child processes to finish..." << endl;

    wait(NULL);  // Wait for a child process to complete
    wait(NULL);  // Wait for the other child process

    cout << "Both child processes have completed. Main process ending." << endl;
    return 0;
}
