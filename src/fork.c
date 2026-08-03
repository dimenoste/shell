#include "apue.h"
#include <sys/wait.h>

// int main(void)
// {
//     char buf[MAXLINE]; /* from apue.h */
//     pid_t pid;
//     int status;
//     printf("%% "); /* print prompt (printf requires %% to print %) */
//     while (fgets(buf, MAXLINE, stdin) != NULL) {
//         if (buf[strlen(buf) - 1] == '\n')
//             buf[strlen(buf) - 1] = 0; /* replace newline with null */
        
//         if ((pid = fork()) < 0) {
//             printf("fork error");
//         } else if (pid == 0) { /* child */
//             execlp(buf, buf, (char *)0);
//             printf("couldn’t execute: %s", buf);
//             exit(127);
//         }
//         /* parent */
//         if ((pid = waitpid(pid, &status, 0)) < 0)
//             printf("waitpid error");
//         printf("%% ");
//     }
//     exit(0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child: redirect standard output to a file
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
        // now exec "wc"...
        char *myargs[3];
        myargs[0] = strdup("wc"); // program: wc
        myargs[1] = strdup("fork.c"); // arg: file to count
        myargs[2] = NULL; // mark end of array
        execvp(myargs[0], myargs); // runs word count
    } else {
    // parent goes down this path (main)
        int rc_wait = wait(NULL);
    }
        return 0;
}