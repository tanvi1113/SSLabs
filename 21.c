/*
===================================================================================
Name : 21.c
Author : Tanvi Motwani
Description : Write a C Program to call fork and print the parent and child process id.
Date: 2nd September, 2023.
===================================================================================
*/


#include<stdio.h>
#include<unistd.h>

int main()
{
	int c_id = fork();
	if(c_id==-1)
	{
		perror("Error in creating child process");
		return 0;
	}
	if(c_id)
	{
		printf("Parent id is: %d\n",getpid());
		printf("Child id is: %d\n",c_id);
	}
	return 0;
}
