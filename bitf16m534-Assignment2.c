#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int cpid=-1;
	int sum1=0;
	int arr[100];
	int sum=0;
	for(int i=0 ; i < 100 ; i++)
	{
		arr[i]=i;
	}

	cpid=fork();
	if(cpid==0)
	{	
		for(int i=0 ; i< 100 ;i++)
		{
			sum=sum+arr[i];
		}
		exit(0);
	}
	else
	{
		int cp=fork();
		if(cp==0)
		{
			for(int i=0 ; i < 100 ; i++)
			{
				sum1=sum1+arr[i];
			}
			exit(0);
		}
		printf("Sum is : %d ",sum1);
	}
	
	return 0;
}
		
