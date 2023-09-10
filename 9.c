/*
============================================================================
Name : 9.c
Author : Tanvi Motwani
Description : Write a C Program to display information about a file.
Date: 26th August, 2023.
============================================================================
*/


#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char* argv[])
{
	if (argc<2)
	{
		printf("File not specified!\n");
		return 0;
	}

	struct stat s;
	int f = stat(argv[1],&s);
	if (f<0)
	{
		printf("Error! No such file exists\n");
		return 0;
	}

	printf("Inode number:%ju\n",s.st_ino);
	printf("Number of Hard Links:%ju\n",s.st_nlink);
	printf("Uid:%u\n",s.st_uid);
	printf("Gid:%u\n",s.st_gid);
	printf("Inode number:%jd bytes\n",s.st_size);
	printf("Block size:%jd bytes\n",s.st_blksize);
	printf("Number of Blocks:%jd\n",s.st_blocks);
	printf("Time of last access:%s\n",ctime(&s.st_atime));
	printf("Time of last modification:%s\n",ctime(&s.st_mtime));
	printf("Time of last change:%s\n",ctime(&s.st_ctime));
	return 0;
}
