/*
============================================================================
Name : 4.c
Author : Tanvi Motwani
Description : Write a C Program to open existing file in read write mode.
              Try O_EXCL flag also.
Date: 18th August, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char fname[20];
	printf("Enter file name\n");
	scanf("%s",fname);
        int fd = open(fname,O_EXCL | O_RDWR);
        if(fd<0)
        {
                perror("Error in Opening File\n");
        }
        else
        {
                printf("File opened Successfully\n");
                printf("File descriptior: %d\n",fd);
        }
        return 0;
}

