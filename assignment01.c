#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipe1[2], pipe2[2];  // setting up the pipess
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid = fork();  // creating child,ig this is gonna work


    return 0;
}
