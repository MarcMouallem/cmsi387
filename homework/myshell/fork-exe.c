#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * This program demonstrates the use of the fork() and exec()
 * functions.
 */
int main() {

    char* commandWithArgs[128]; // holds command at index 0 and arguments thereafter
    int argIndex;
    int reachedEndOfArgs;
    int ampersandFlag;

    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);

    int endOfTransmission = 0;
    
    while (!endOfTransmission) {

        char input[256] ="\\x04"; // holds input to run
        reachedEndOfArgs = 0;
        ampersandFlag = 0;

        printf("%s%s%s%s", hostname, ":", (char*) get_current_dir_name(), "$"); // prints prompt

        fgets(input, 256, stdin); // reads in input

        commandWithArgs[0] = strtok(input, " \n"); // reads in command

        if (commandWithArgs[0] == NULL) { // no command

            /* reads next line */

            // JD: strncmp is considered to be a safer option.
        } else if (strcmp(commandWithArgs[0], "\\x04") == 0) { // exit command or EOT

            printf("\n");
            endOfTransmission = 1; // exit shell

        } else if (strcmp(commandWithArgs[0], "exit") == 0) {

            endOfTransmission = 1; // exit shell

        } else {

            /* parses arguments into commandWithArgs */
            for (argIndex = 1; !reachedEndOfArgs; argIndex++) {

                commandWithArgs[argIndex] = strtok(NULL, " \n"); // reads in arguments

                /* checks if reached end of argguments and checks for ampersand */
                if (commandWithArgs[argIndex] == NULL) {
                    if (strcmp(commandWithArgs[argIndex - 1], "&") == 0) {
                        ampersandFlag = 1;
                        commandWithArgs[argIndex - 1] = NULL;
                    }
                    reachedEndOfArgs = 1;
                }

            }

            if (strcmp(commandWithArgs[0], "cd") == 0) { // checks for cd before fork
           
                chdir(commandWithArgs[1]); // changes directory

            } else {

                pid_t pid; // stores the fork result
                pid = fork(); // preforms fork

                if (pid < 0) {

                    /* error condition. */

                    fprintf(stderr, "Fork failed\n");
                    return -1;

                } else if (pid == 0) {

                    /* child process. */

                    /* runs commands */
                    if (strcmp(commandWithArgs[0], "secret-system-call") == 0) {
                        // JD: How do I know that blarkar will indeed invoke the
                        //     secret system call?
                        if (execlp("blarkar", "blarkar", NULL) == -1) {
                            exit(1);
                        }
                    } else {
                        if (execvp(commandWithArgs[0], commandWithArgs) == -1) {
                            exit(1);
                        }
                    }
              
                } else {

                    /* parent process. */
                    
                    int result;
                    if (!ampersandFlag) {
                        wait(&result);
                    }

                }

            }

        }

    }

    return 0;
}
