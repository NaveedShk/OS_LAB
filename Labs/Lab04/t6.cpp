#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <signal.h>

using namespace std;

// Signal handler for the alarm signal
void handleAlarm(int sig) {
    cout << "\nAlarm signal received. Terminating program..." << endl;
    exit(0);
}

int main() {
    // Register signal handler for SIGALRM
    signal(SIGALRM, handleAlarm);
    alarm(5);

    cout << "Entering sleep loop..." << endl;

    while (true) {
        cout << "Program is still running..." << endl;
        sleep(1);
    }

    return 0;
}
