/*
==============================================================================
Name : 3.c
Author : Tanvi Motwani
Description : Write a C Program to create file and print its descriptor value.
Date: 18th August, 2023.
==============================================================================
*/


#include <stdio.h>
#include <fcntl.h>

int main()
{
	char fname[20];
	printf("Enter file name\n");
	scanf("%s",fname);
        int fd= creat(fname,O_CREAT);
        if(fd<0)
        {
                perror("File not created\n");
        }

        else
        {
                printf("File created Successfully\n");
                printf("File descriptor: %d\n",fd);
        }
        return 0;
}


