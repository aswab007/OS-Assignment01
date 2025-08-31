#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipe1[2], pipe2[2];  // seting up pipess
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid = fork(); // creating child,ig this ll work

    if (pid == 0) {
        // child part gonna come here

    } else {
        // parent part gonna come here

    return 0;
}

