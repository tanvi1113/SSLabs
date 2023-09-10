/*
===================================================================================
Name : 12.c
Author : Tanvi Motwani
Description : Write a C Program to find out the opening mode of a file. Use fcntl.
Date: 27th August, 2023.
===================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
        if (argc<2)
        {
                printf("File name not specified\n");
                return 0;
        }

        int fd = open(argv[1],O_RDWR);
        if (fd<0)
        {
                printf("File does not exist!\n");
                return 0;
        }
	printf("File access mode:%d\n",fcntl(fd,F_GETFL));
	int cl = close(fd);
	return 0;
}
