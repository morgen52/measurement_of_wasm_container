
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int flag = 1;

void heapPermute(int n, int arr[],int arrLen){
	int temp;
	int i;
	
	if(n==1){
		printf("\n[");
		
		for(i=0;i<arrLen;i++)
			printf("%d,",arr[i]);
		printf("\b] Sign : %d",flag);
		
		flag*=-1;
	}
	else{
		for(i=0;i<n-1;i++){
			heapPermute(n-1,arr,arrLen);
			
			if(n%2==0){
				temp = arr[i];
				arr[i] = arr[n-1];
				arr[n-1] = temp;
			}
			else{
				temp = arr[0];
				arr[0] = arr[n-1];
				arr[n-1] = temp;
			}
		}
		heapPermute(n-1,arr,arrLen);
	}
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argC,char* argV[0])
{
	struct timeval my_tv;
	gettimeofday(&my_tv,NULL);
	time_t my_t = my_tv.tv_sec;
	long my_us = my_tv.tv_usec;
	struct tm *my_tm;
	char my_buf[1024];
	my_tm = localtime(&my_t);
	strftime(my_buf, sizeof(my_buf), "%M:%S", my_tm);
	printf("start complete time:%s.%06ld\n", my_buf, my_us);
// additional code
	int *arr, i=0, count = 1;
	char* token;
	
	if(argC==1)
		printf("Usage : %s <comma separated list of integers>",argV[0]);
	else{
		while(argV[1][i]!=00){
			if(argV[1][i++]==',')
				count++;
		}
		
		arr = (int*)malloc(count*sizeof(int));
		
		i = 0;
		
		token = strtok(argV[1],",");
		
		while(token!=NULL){
			arr[i++] = atoi(token);
			token = strtok(NULL,",");
		}
		
		heapPermute(i,arr,count);
	}
		
	return 0;
}
