#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    fd = open("input.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }


    bytesRead = read(fd, buffer, BUFFER_SIZE);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (pid == 0) {  // Child Process
        const char *msg = "Processed by child process\n";
        lseek(fd, 0, SEEK_END);  // Move to end of file
        write(fd, msg, strlen(msg));
        close(fd);

     
        execlp("cat", "cat", "input.txt", NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
    } else {  
        wait(NULL);  
        close(fd);
    }

    return 0;
}
