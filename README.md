# Shell
Custom Command Line Interpreter in C
This project involves the creation of a custom command line interpreter using the C language. The interpreter provides an interactive mode which allows the user to enter commands, and these commands are executed simultaneously or concurrently if separated by a ';'.
Project Features:
* The program can handle multiple commands at the same time.
* The fork() function is used to create a child process and exec() is used to execute each command. More specifically, we used execvp to execute the command.
* The shell stops accepting new commands when it encounters the quit command or reaches the end of the input stream. If the quit command is on the same line as other commands, the shell ensures that the other commands are executed (and finished) before quitting.
* We are restricted from using the system() system call and libc functions like fopen(), fread(), etc. to handle file I/O. The only libc function used in this project is fgets().
    * The following additional libc functions are used:
    * strtok() for splitting a string into tokens.
    * strcspn() for calculating the length of the substring.
    * strcmp() for comparing two strings.
    * perror() for giving error messages and continuing processing until the quit command.
The functions open(), read(), write() are not used as the first head functions. Instead, the function execute() manages this, thereby avoiding a compilation error stating that file.txt cannot be accessed without authorized permissions.
Compiling Instructions:
To compile any C file use the following command:

$ gcc -o <output filename> <Filename>.c

To run the output:

$ ./output filename

To run in batch mode:

$ ./output filename < filename.txt

In the .txt file, we use commands separated by ';'.

Sample Test Run:
Please refer to the project description for a detailed test run.

Known Issues:
While the shell can be accessed in both batch mode and interactive mode, the interactive mode is more likely to get interrupted when the keyboard input is invoked through the execute function.

Please remember to replace <output filename> and <Filename>.c with the actual output filename and C source filename you're using, respectively.
