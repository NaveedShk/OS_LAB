//Producer Code
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    int fd;
    char buffer[BUFSIZ];
    ssize_t num_bytes;

    // Create the named pipe (FIFO)
    mkfifo(FIFO_FILE, 0666);

    // Open the named pipe for writing (producer)
    fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) { // Producer loop
        printf("Producer: Enter a message (or 'exit' to quit): ");
        fgets(buffer, BUFSIZ, stdin); // Read input from user

        num_bytes = write(fd, buffer, strlen(buffer)); // Write input to the named pipe
        if (num_bytes == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        if (strncmp(buffer, "exit", 4) == 0) { // Check for exit condition
            break;
        }
    }

    close(fd);          // Close the named pipe
    unlink(FIFO_FILE);  // Remove the named pipe from the file system

    return 0;
}




//consumer code
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    int fd;
    char buffer[BUFSIZ];
    ssize_t num_bytes;

    // Open the named pipe for reading
    fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) { // Consumer loop
        num_bytes = read(fd, buffer, BUFSIZ); // Read from the pipe
        if (num_bytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buffer[num_bytes] = '\0'; // Null-terminate the string
        printf("Consumer: Received message: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) { // Check for exit condition
            break;
        }
    }

    close(fd); // Close the named pipe
    return 0;
}
