/*
===================================================================================
Name : 15.c
Author : Tanvi Motwani
Description : Write a C Program to display the environmental variable of the user.
Date: 28th August, 2023.
===================================================================================
*/


#include<stdlib.h>
#include<stdio.h>

int main()
{
	char* user = getenv("USER");
	if (user == NULL)
	{
		printf("Error");
	}
	else
	{
		printf("Environmental variable for user is: %s\n",user);
	}

	return 0;
}
