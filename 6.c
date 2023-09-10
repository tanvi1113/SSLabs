/*
============================================================================
Name : 6.c
Author : Tanvi Motwani
Description : Write a C Program using sys calls to take input from STDIN and 
	      display on STDOUT.
Date: 18th August, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	char buff[100];
	int rcount,wcount;
	printf("Input:\n");
	rcount = read(0,&buff,100);
	wcount = write(1,&buff,rcount);
	return 0;
}

