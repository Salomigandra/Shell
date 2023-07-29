#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define Maximum_Lines 100
#define Maximum_args 20
#define Maximum_commands 20

/* Parse_cmds used to seperate the function by (;) and the resluting commands are stored in commands array  */

int parsing_commands(char* lines, char** commands) {
    int i = 0;
    char* token = strtok(lines, ";");/* used strtok libc function to split a string into tokens */
    while (token != NULL && i < Maximum_commands - 1) {
        commands[i++] = token;
        token = strtok(NULL, ";");
    }
    commands[i] = NULL;
    return i;
}
/* seperating each command by using parsing_args based on the seperator. storing arguments in the args array.   */

int parsing_args(char* cmd, char** args) {
    int i = 0;
    char* token = strtok(cmd, " ");/* used strtok libc function to split a string into tokens */
    while (token != NULL && i < Maximum_args - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return i;
}
/* execute function - to execute the shell command by forking a child process using fork() system call. child process uses 'execvp' to replace the child process  */
void execute(char** args) {
    pid_t pid = fork();
    if (pid == 0) {
       if (execvp(args[0], args) == -1){
        perror("execvp");
    	}
	} else if (pid < 0) {
        perror("fork");
    } else {
        int status;
/* parent process waits for the child process to complete execution */
       if ( waitpid(pid, &status, 0) == -1) {
	perror("waitpid");
	}
    }
}

int main(int argc, char* argv[]) {
    char lines[Maximum_Lines];
    char* commands[Maximum_commands];
    char* args[Maximum_args];
/*infinite loop for prompt to execute until user entered quit command and used 'break' to execute before exiting from shell */
    while (1) {
        printf("Group27 $  ");
/* fgets() to capture the user keyboard input from the specified stream and stores it */
        fgets(lines, Maximum_Lines, stdin); /* stdin used as an argument to read from the standard input.*/
        lines[strcspn(lines, "\n")] = '\0';

        int n_cmds = parsing_commands(lines, commands);
        int i;
        int quit_check = 0;/* used quit_check to exit or terminate the program using quit  */
        for (i = 0; i < n_cmds; i++) {
            int n_args = parsing_args(commands[i], args);
            if (strcmp(args[0], "quit") == 0) { /* Used strcmp to compare strings untill user enters quit command */
                quit_check = 1;
            } else {
                execute(args);
            }
        }
        /* if quit_check is equlas to 0 then it will quit if it is 1 it will continue */
        if (quit_check) {
            break; /*exit the loop when the break statement is executed */
        }
    }

    return 0;
}
