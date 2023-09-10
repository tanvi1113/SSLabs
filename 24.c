/*
===================================================================================
Name : 24.c
Author : Tanvi Motwani
Description : Write a C Program to create an orphan process.
Date: 4th Septmeber, 2023.
===================================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	int c_id = fork();
	if(c_id==-1)
	{
		printf("Error in creating child process\n");
	}
	else
	{
		if(c_id)
		{
			printf("Parent id is %d\n",getpid());
			printf("Parent is exiting\n");
		}
		else
		{
			sleep(5);
			printf("Parent id of child process is %d\n",getppid());
		}
	}
	return 0;
}
