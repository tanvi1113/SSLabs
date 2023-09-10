/*
===================================================================================
Name : 13.c
Author : Tanvi Motwani
Description : Write a C Program to wait for a STDIN for 10 seconds. Check if the 
	      data is available within 10 seconds.
Date: 27th August, 2023.
===================================================================================
*/


#include<stdio.h>
#include<sys/select.h>

int main()
{
	fd_set fd;
	struct timeval t;
	t.tv_sec=10;
	t.tv_usec=0;
	FD_ZERO(&fd);
	FD_SET(0,&fd);
	int val = select(1,&fd,NULL,NULL,&t);
	if (val == 0)
	{
		printf("Input not entered in 10 seconds!\n");
		return 0;
	}
	else
	{
		printf("Input entered in 10 seconds\n");
	}
	return 0;
}
