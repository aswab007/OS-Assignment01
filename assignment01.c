#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid = fork();

    if (pid == 0) {
        close(pipe1[1]);
        close(pipe2[0]);

        int message;
        for (int i = 0; i < 1000000; i++) {
            read(pipe1[0], &message, sizeof(int));
            write(pipe2[1], &message, sizeof(int));
        }

        close(pipe1[0]);
        close(pipe2[1]);
    } else {
        close(pipe1[0]);
        close(pipe2[1]);

        struct timeval start, end;
        gettimeofday(&start, NULL);

        int message;
        for (int i = 0; i < 1000000; i++) {
            message = i;
            write(pipe1[1], &message, sizeof(int));
            read(pipe2[0], &message, sizeof(int));
        }

        gettimeofday(&end, NULL);

        close(pipe1[1]);
        close(pipe2[0]);
        wait(NULL);
    }

    return 0;
}
