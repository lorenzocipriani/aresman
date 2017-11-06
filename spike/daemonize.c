/*
 * daemonize.c
 *
 *  Created on: 2017-09-29
 *      Author: Lorenzo Cipriani <lorenzo1974@gmail.com>
 *     Website: https://www.linkedin.com/in/lorenzocipriani
 *
 *  References: D. Watson, "Linux Daemon Writing HOWTO", v1.0, May 2004
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(void) {

        /* Our process ID and Session ID */
        pid_t pid, sid;

        /* Fork off the parent process */
        printf("Fork off the parent process\n");
        pid = fork();
        if (pid < 0) {
                printf("Fork failed [%d]\n", pid);
                exit(EXIT_FAILURE);
        }
        /* If we got a good PID, then
           we can exit the parent process. */
        if (pid > 0) {
                printf("Fork succeeded [%d]\n", pid);
                exit(EXIT_SUCCESS);
        }

        /* Change the file mode mask */
        printf("Change the file mode mask\n");
        umask(0);

        /* Open any logs here */

        /* Create a new SID for the child process */
        printf("Create a new SID for the child process\n");
        sid = setsid();
        if (sid < 0) {
                printf("SID failed [%d]\n", sid);
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
        printf("New SID [%d]\n", sid);



        /* Change the current working directory */
        printf("Change the current working directory\n");
        if ((chdir("/")) < 0) {
                printf("Change directory failed\n");
                /* Log the failure */
                exit(EXIT_FAILURE);
        }

        /* Close out the standard file descriptors */
        printf("Close out the standard file descriptors\n");
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        printf("Standard file descriptors closed (this message should not be seen)\n");

        /* Daemon-specific initialization goes here */

        /* The Big Loop */
        while (1) {
           /* Do some task here ... */

           sleep(30); /* wait 30 seconds */
        }
   exit(EXIT_SUCCESS);
}
