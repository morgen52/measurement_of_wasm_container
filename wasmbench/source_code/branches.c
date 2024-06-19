#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a(int a, int b){

	if(a > 10)
	{
		printf("a");

		if(b > a){
			printf("b > a");
		}
		if(b > 100){
			printf("wait ... b > 100");
		}
	}
	else{
		printf("No condition for a");

		if( b > 10000){
			printf("Yet b > 1000");
		}
	}

	return 0;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(){
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
	a(100, 100);
	return 0;
}