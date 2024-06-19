
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
	int police,sanitation,fire;
	
	printf("Police     Sanitation         Fire\n");
	printf("----------------------------------");
	
	for(police=2;police<=6;police+=2){
		for(sanitation=1;sanitation<=7;sanitation++){
			for(fire=1;fire<=7;fire++){
				if(police!=sanitation && sanitation!=fire && fire!=police && police+fire+sanitation==12){
					printf("\n%d\t\t%d\t\t%d",police,sanitation,fire);
				}
			}
		}
	}
	
	return 0;
}
