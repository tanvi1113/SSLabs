/*
===================================================================================
Name : 16.c
Author : Tanvi Motwani
Description : Write a C Program to implement mandatory locking.
	      Implement read and write lock.
Date: 28th August, 2023.
===================================================================================
*/


#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	struct flock rdlck;
	rdlck.l_whence = SEEK_SET;
	rdlck.l_start = 0;
	rdlck.l_len = 0;
	rdlck.l_pid = getpid();
	if (argc<2)
        {
                printf("File name not specified!\n");
                return 0;
        }

        int fd = open(argv[1],O_RDWR);
        if (fd<0)
        {
                printf("File could not be opened\n");
                return 0;
        }
	char c;
	printf("Before Critical Section\n");
	printf("Read(R) or Write(W)?\n");
	scanf("%c",&c);
	if(c=='R')
	{
		rdlck.l_type = F_RDLCK;
	}
	else
	{
		rdlck.l_type = F_WRLCK;
	}
	int f = fcntl(fd,F_SETLKW,&rdlck);
	if( f<0)
        {
                printf("Could not perform locking\n");
        }
	else
        {
                printf("Lock Successfull\n");
        }
	printf("Enter Q to release lock\n");
	scanf("%c",&c);
	while(c!='Q')
	{
		scanf("%c",&c);
	}
	f = fcntl(0,F_GETLK,&rdlck);
	if( f<0)
        {
                printf("Could not perform unlocking\n");
        }
        else
        {
                printf("Unlock Successfull\n");
        }
	printf("Exit Critical Section\n");
	close(fd);
	return 0;
}
