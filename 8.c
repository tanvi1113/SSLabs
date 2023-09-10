/*
============================================================================
Name : 8.c
Author : Tanvi Motwani
Description : Write a C Program to open file in read only mode.
              Read and display contents line by line.
Date: 25th August, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	if (argc<2)
	{
		printf("No file Specified\n");
		return 0;
	}
	
	int fd = open(argv[1],O_RDONLY);
	if (fd<0)
	{
		printf("File does not exist\n");
		return 0;
	}

	int rdcount,wrcount;
	int i=0;
	char line[100];
	char buff;
	rdcount = read(fd,&buff,1);
	while(rdcount!=0)
	{
		while(buff!='\n')
		{
			wrcount = write(1,&buff,1);
			rdcount = read(fd,&buff,1);
		}
		
		printf("\n");
		rdcount = read(fd,&buff,1);
	}
	int f = close(fd);
	if (f <0)
	{
		printf("File could not be closed");
	}
	return 0;
}

