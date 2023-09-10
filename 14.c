/*
===================================================================================
Name : 14.c
Author : Tanvi Motwani
Description : Write a C Program to find the type of a file.
Date: 27th August, 2023.
===================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

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
	struct stat s;
	int s1 = lstat(argv[1],&s);
	if (s1<0)
	{
		printf("Error in Obtaining File Status\n");
		return 0;
	}	
	printf("File type is: ");
	switch (s.st_mode & S_IFMT) 
	{
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
         }
        int cl = close(fd);
        return 0;
}


