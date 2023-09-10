/*
===================================================================================
Name : 25.c
Author : Tanvi Motwani
Description : Write a C Program to create three child processes.
	      The parent should wait for a particular child
Date: 8th September, 2023.
===================================================================================
*/


#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int c[3];
	int choice;
	printf("Enter which process should parent wait for:\n");
	scanf("%d",&choice);
	int w;
	for(int i=0;i<3;i++)
	{
		c[i] = fork();
		if(c[i]==-1)
		{
			printf("Error in creating child %d\n",i+1);
			return 0;
		}
		if(c[i]!=0)
		{
			continue;
		}
		else if(i==choice-1)
		{
			sleep(5);
			printf("Child:%d terminated sucessfully!\n",i+1);
			return 0;
		}
		else
		{
			printf("Child:%d terminated successfully!\n",i+1);
			return 0;
		}
	}
	waitpid(c[choice-1],&w,0);
	printf("Parent terminated sucessfully!\n");
	return 0;

}

