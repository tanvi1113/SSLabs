/*
===================================================================================
Name : 27.c
Author : Tanvi Motwani
Description : Write a program to execute ls -Rl by the following system calls
		a. execl
		b. execlp
		c. execle
		d. execv
		e. execvp
Date: 8th September, 2023.
===================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int c;
	c = fork();
	if(c==-1)
	{
		printf("Error\n");
		return 0;
	}
	else
	{
		if(c==0)
		{
			printf("Execution using execl() system call\n");
	                execl("/usr/bin/ls","ls","-Rl",NULL);
        	        exit(1);
		}
	}
	wait(NULL);
	c = fork();
        if(c==-1)
        {
                printf("Error\n");
                return 0;
        }
        else
        {
                if(c==0)
                {
                        printf("Execution using execlp() system call\n");
	                execlp("/usr/bin/ls","ls","-Rl",NULL);
        	        exit(1);
                }
        }
	wait(NULL);
	c = fork();
        if(c==-1)
        {
                printf("Error\n");
                return 0;
        }
        else
       	{
                if(c==0)
                {
			char * envp[2];
                	envp[0]="use/bin/ls";
                	envp[1]="-Rl";
		       	printf("Execution using execle() system call\n");
	                execle("/usr/bin/ls","ls","-Rl",NULL,envp);
        	        exit(1);
                }
        }
	wait(NULL);
	c = fork();
        if(c==-1)
        {
                printf("Error\n");
                return 0;
        }
        else
        {
                if(c==0)
                {
		char * argv[2];
		argv[0] = "/usr/bin/ls";
		argv[1] = "-Rl";
                     printf("Execution using execv() system call\n");
        	     execv("/usr/bin/ls",argv);
	             exit(1);

                }
        }
	wait(NULL);
	c = fork();
        if(c==-1)
        {
                printf("Error\n");
                return 0;
        }
        else
        {
                if(c==0)
                {
			char * argv[2];
                	argv[0] = "/usr/bin/ls";
                	argv[1] = "-Rl";
			printf("Execution using execvp() system call\n");
                	execvp("/usr/bin/ls",argv);
                	exit(1);
                }
        }
	wait(NULL);
	return 0;
}
