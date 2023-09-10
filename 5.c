/*
==================================================================================
Name : 5.c
Author : Tanvi Motwani
Description : Write a C Program to create five new files with infinite loop.
              Execute in background and check file descriptors in /proc directory.
Date: 18th August, 2023.
==================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
int main()
{
        int fd1 = creat("f1.txt",O_CREAT);
        int fd2 = creat("f2.txt",O_CREAT);
        int fd3 = creat("f3.txt",O_CREAT);
        int fd4 = creat("f4.txt",O_CREAT);
        int fd5 = creat("f5.txt",O_CREAT);
        if(fd1<0)
        {
                perror("f1.txt not created");
        }
        else
        {
                printf("f1.txt created successfully");
        }
        if(fd2<0)
        {
                perror("f2.txt not created");
        }
        else
        {
                printf("f2.txt created successfully");
        }
        if(fd3<0)
        {
                perror("f3.txt not created");
        }
        else
        {
                printf("f3.txt created successfully");
        }
        if(fd4<0)
        {
                perror("f4.txt not created");
        }
        else
        {
                printf("f4.txt created successfully");
        }
        if(fd5<0)
        {
                perror("f5.txt not created");
        }
        else
	{
                printf("f5.txt created successfully");
        }
	while(1)
        {
        }
        return 0;
}


// run program in background using &
// run command ls -l /proc/pid/fd to see file descriptors
