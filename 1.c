/*
============================================================================
Name : 1.c
Author : Tanvi Motwani
Description : Write a C Program to create softlink, hardlink and fifo files
Date: 11th August, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	char f1[20],f2[20];
	printf("Enter filename to be pointed by softlink\n");
	scanf("%s",f1);
	printf("Enter softlink filename\n");
        scanf("%s",f2);	
        int sft = symlink(f1,f2);
        if(sft<0)
        {
                perror("Failed sotflink\n");
                return 1;
        }
	else
	{
		printf("Softlink file created successfully!\n");
	}

	printf("Enter filename to be pointed by hardlink\n");
        scanf("%s",f1);
        printf("Enter hardlink filename\n");
        scanf("%s",f2);
        int hrd = link(f1,f2);
        if(hrd<0)
        {
                perror("Failed hardlink\n");
                return 1;
        }
	else
        {
                printf("Hardlink file created successfully!\n");
        }

	printf("Enter pipename\n");
        scanf("%s",f1);
        int p = mknod(f1,S_IFIFO,0);
        if(p<0)
	{
                perror("Faile pipe\n");
	}
	else
        {
                printf("Pipe created successfully!\n");
        }

        return 0;
}

