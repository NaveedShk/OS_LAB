//modified producer code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    const int SIZE = 4096;
    const char *name = "OS";
    const char *message_0 = "Hello";
    const char *message_1 = "World";
    int fd;
    char *ptr;

    fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);
    ptr = (char *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    // Forking the process
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {  // Child Process (Consumer)
        execl("./consumer", "consumer", NULL);
    } else {  // Parent Process (Producer)
        sprintf(ptr, "%s", message_0);
        ptr += strlen(message_0);
        sprintf(ptr, "%s", message_1);
        ptr += strlen(message_1);
    }

    return 0;
}



///consumer code to print second message
#include <stdio.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
    const int SIZE = 4096;
    const char *name = "OS";
    int fd;
    char *ptr;

    fd = shm_open(name, O_RDONLY, 0666);
    ptr = (char *) mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);

    printf("Consumer: Received message: %s %s\n", ptr, ptr + 5); // Print both messages

    shm_unlink(name);  // Remove shared memory

    return 0;
}
