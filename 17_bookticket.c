/*
===================================================================================
Name : 17_bookticket.c
Author : Tanvi Motwani
Description : Write a C Program to open the file, implement write lock, read the
	      ticket number, increment the number and print the new ticket number
	      then close the file.
Date: 28th August, 2023.
===================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
        int fd = open("ticket.txt",O_RDWR);
        if(fd<0)
        {
                printf("File could not be opened\n");
                return 0;
        }
	struct flock f;
	f.l_type = F_WRLCK;
	f.l_whence = SEEK_SET;
	f.l_start = 0;
	f.l_len = 0;
	f.l_pid = getpid();
	printf("Before entering the critical section\n");
	int l = fcntl(fd,F_SETLKW,&f);
	if (l<0)
	{
		printf("Error in locking");
		return 0;
	}
	int n;
	int rcount = read(fd,&n,sizeof(int));
	n+=1;
	int lseek_ = lseek(fd,0,SEEK_SET);
	if(lseek_<0)
	{
		printf("Error in lseek\n");
		return 0;
	}
	int wcount = write(fd,&n,sizeof(int));
	char c;
	printf("Press Q to exit critical section\n");
	scanf("%c",&c);
	while(c!='\n')
	{
		scanf("%c",&c);

	}
	l = fcntl(fd,F_GETLK,&f);
	if(n<0)
	{
		printf("Error in unlocking!\n");
	}
	printf("Ticket number: %d\n",n);
	printf("Record updated successfully!\n");
        return 0;
}

