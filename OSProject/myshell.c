/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };

    
    // Parse the commands provided using argc and argv
    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        if(buffer[strlen(buffer)-1]=='\n'){
            buffer[strlen(buffer)-1]='\0';
        }
        arg[0] = '\0';
        // Perform string tokenization to get the command and argument
        char *token;
        token = strtok(buffer, " ");
        int i = 0;
        while( token != NULL ) {

            if(i==0){
                strcpy(command, token);
                printf("Command: %s\n", command);

            }
            else{
                strcat(arg, token);
                printf("Arguments: %s\n", arg);

            }
            i++;
            token = strtok(NULL, " ");
            if(token != NULL){
                strcat(arg, " ");
            } 
        }

        printf("command: %s\n", command);
        printf("arg: %s\n", arg);

        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0)
        {
            // your code here
        }

        // other commands here...
        
        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
    }
    return EXIT_SUCCESS;
}
