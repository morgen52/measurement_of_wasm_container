
#include<stdio.h>

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main()
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
	int arr[5] = {0, 2, 11, 19, 90},sum = 21,i,j,check = 0;
	
	for(i=0;i<4;i++){
		for(j=i+1;j<5;j++){
			if(arr[i]+arr[j]==sum){
				printf("[%d,%d]",i,j);
				check = 1;
				break;
			}
		}
	}
	
	if(check==0)
		printf("[]");
	
	return 0;
}
