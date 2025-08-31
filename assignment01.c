#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 

int main() { 
    int pipe1[2], pipe2[2]; // pipes
    pipe(pipe1); 
    pipe(pipe2); 

    pid_t pid = fork(); // child

    if (pid == 0) { 
        close(pipe1[1]); // child will not write here 
        close(pipe2[0]); // child will not read from here

        int message; 
        for (int i = 0; i < 1000000; i++) { 
            read(pipe1[0], &message);  // reading number from parent         // will handle this error subha
            write(pipe2[1], &message);  // sending number back to parent
        } 
    } 

    return 0; 
} 
