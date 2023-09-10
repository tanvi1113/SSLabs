/*
===================================================================================
Name : 22.c
Author : Tanvi Motwani
Description : Write a C Program to open a file, call fork, and then write to the
	      file by both the child as well as the parent processes.
	      Check output of the file.
Date: 2nd September, 2023.
===================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
	if(argc<2)
	{
		printf("Specify filename\n");
		return 0;
	}
	int fd = open(argv[1],O_RDWR,00600);
	if(fd<0)
	{
		printf("File does not exist\n");
		return 0;
	}
	char c1[40] = "This text is written by parent\n";
        char c2[40] = "This test is written by child\n";
	int wcount = write(fd,c1,sizeof(c1));
	if(wcount<0)
	{
		printf("Error in writing by parent\n");
		return 0;
	}
	int c_id = fork();
        if(c_id==-1)
        {
                perror("Error in creating child process\n");
                return 0;
        }
        if(!c_id)
	{
		lseek(fd,0,SEEK_CUR);
		wcount = write(fd,c2,sizeof(c2));
		if(wcount<0)
		{
			printf("Error in writing by child process");
		}
	}
	return 0;
}
