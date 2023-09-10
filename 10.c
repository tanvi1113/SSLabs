/*
============================================================================
Name : 10.c
Author : Tanvi Motwani
Description : Write a C Program to open a file with read write mode, write 10
	      bytes, move the file pointer by 10 bytes (use lseek) and write 
	      again 10 bytes. Check return value of lseek
Date: 26th August, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	if (argc<2)
	{
		printf("File name not specified!\n");
		return 0;
	}

	int fd = open(argv[1],O_RDWR|O_CREAT);
	if (fd<0)
	{
		printf("File could not be created\n");
		return 0;
	}

	char buff[10];
	printf("Enter 10 bytes of data:\n");
	scanf("%s",buff);
	int wrcount = write(fd,buff,10);
	int count = lseek(fd,10,SEEK_CUR);
	if (count<0)
	{
		printf("Could not move pointer to 10 bytes\n");
		return 0;
	}
	else
	{
		printf("Moved file pointer by 10 bytes\n");
	}
	printf("Enter 10 bytes of data:\n");
        scanf("%s",buff);
        wrcount = write(fd,buff,10);
	count = lseek(fd,0,SEEK_CUR);
	if (count<0)
        {
                printf("Could not get lseek value\n");
                return 0;
        }
	printf("Return value of lseek: %d\n",count);
	int cl = close(fd);
	return 0;
}

//od -a filename
