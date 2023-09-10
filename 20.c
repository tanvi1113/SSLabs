/*
===================================================================================
Name : 20.c
Author : Tanvi Motwani
Description : Write a C Program to find out the priority of your running program.
	      Modify the priority with nice command.
Date: 1st Septmeber, 2023.
===================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include <errno.h>

int main()
{
	int prior;
	errno = 0;
	int p = getpriority(PRIO_PROCESS,0);
	if(errno==1)
	{
		perror("Error!!\n");
		return 0;
	}
	printf("Before: Priority of Process is %d\n",p);
	printf("Enter nice Value:\n");
	scanf("%d",&prior);
	errno=0;
	p = nice(prior); 
	if(errno!=0)
	{
		perror("Error in setting priority");
		return 0;
	}
	printf("After: Priority of Process is %d\n",p);
	return 0;
}
