/*
===================================================================================
Name : 29.c
Author : Tanvi Motwani
Description : Write a C Program to get scheduling policy and modify the
	      scheduling policy (SCHED_FIFO,SCHED_RR).
Date: 8th September, 2023.
===================================================================================
*/


#include<stdio.h>
#include<sched.h>
#include<errno.h>
#include<unistd.h>

int main()
{
	errno=0;
	int val = sched_getscheduler(getpid());
	if(errno==1)
	{
		printf("Error in getting scheduling policy\n");
		return 0;
	}
	else
	{
		switch(val)
		{
			case SCHED_FIFO:
				{
					printf("Policy is SCHED_FIFO\n");
					break;
				}
			case SCHED_RR:
				{
					printf("Polict is SCHED_RR\n");
					break;
				}
			case SCHED_OTHER:
				{
					printf("Policy is SCHED_OTHER\n");
					break;
				}
			default:
				{
					printf("Policy is not known\n");
                                        break;
                                }
		}
		
	}
	errno = 0;
	struct sched_param s;
	s.sched_priority = 10;
	printf("Choose from scheduling policy to set for process:\n1:SCHED_FIFO\n2:SCHED_RR\n");
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		val = sched_setscheduler(0,SCHED_FIFO,&s);
	}
	else
	{
		val = sched_setscheduler(0,SCHED_RR,&s);
	}
	if(errno ==1)
	{
		printf("Error in setting scheduling policy\n");
		return 0;
	}
	else
	{
		val = sched_getscheduler(getpid());
		switch(val)
                {
                        case SCHED_FIFO:
                                {
                                        printf("Policy is SCHED_FIFO\n");
                                        break;
                                }
                        case SCHED_RR:
                                {
                                        printf("Polict is SCHED_RR\n");
                                        break;
                                }
                        case SCHED_OTHER:
                                {
                                        printf("Policy is SCHED_OTHER\n");
                                        break;
                                }
                        default:
                                {
                                        printf("Policy is not known\n");
                                        break;
                                }
                }
	}
	return 0;
}
