#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        cout << "Child process creation failed. ID: " << getpid() << endl;
    } 
    else if (pid == 0) {
        cout << "Child process is running. ID: " << getpid() << endl;
        
        for (int i = 0; i < 100; i++) {
            cout << "I am in Child Process" << endl;
        }
        exit(0);
    } 
    else {
        wait(NULL);
        cout << "Parent process is running. ID: " << getpid() << endl;
        
        for (int i = 0; i < 100; i++) {
            cout << "I am in Parent Process" << endl;
        }
    }
    
    return 0;
}
