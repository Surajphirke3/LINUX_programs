#include <stdio.h>
#include <unistd.h> // for fork(), getpid(), getppid()

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Error in fork
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child Process: \n");
        printf("Child PID: %d\n", getpid());   // getpid() returns child's process ID
        printf("Parent PID: %d\n", getppid()); // getppid() returns parent's process ID
    } else {
        // Parent process
        printf("Parent Process: \n");
        printf("Parent PID: %d\n", getpid());   // getpid() returns parent's process ID
        printf("Child PID: %d\n", pid);         // pid is the child PID returned by fork
    }

    return 0;
}
