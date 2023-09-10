/*
===================================================================================
Name : 23.c
Author : Tanvi Motwani
Description : Write a C Program to create a Zombie state of the running program.
Date: 3rd September, 2023.
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
		return 0;
	}
	if(c_id)
	{
		sleep(10);
		printf("Parent process is exiting\n");
	}
	else
	{
		printf("Child process is exiting\n");
	}
	return 0;
}
