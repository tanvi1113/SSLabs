/*
============================================================================
Name : 7.c
Author : Tanvi Motwani
Description : Write a C Program to copy file1 into file2.
Date: 25th August, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
	if (argc<3)
	{
		printf("Error! Specify both file names\n");
		return 0;
	}
	else
	{
		int fd1 = open(argv[1],O_RDONLY);
		if (fd1<0)
		{
			printf("Source file does not exist!\n");
			return 0;
		}
		int fd2 = open(argv[2],O_RDWR|O_CREAT);
		if (fd2<0)
		{
			printf("Destination file cannot be created!\n");
			return 0;
		}
		char buff;
		int rcount,wcount;
		rcount = read(fd1,&buff,1);
		while (rcount!=0)
		{
			wcount = write(fd2,&buff,1);
			rcount = read(fd1,&buff,1);
		}
		int src_close=close(fd1);
		int dest_close=close(fd2);
		if (src_close<0 || dest_close< 0)
		{
			printf("Problem in closing files!\n");
		}
		else
		{
			printf("File copied Successfully!\n");
		}
	}
	return 0;
}
