#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a(int a){

	if(a > 10)
	{
		printf("a");

		if(a > 100){
			printf("Crashing branch 3\n");
			exit(12);
		}

	}
	else{
		printf("Crashing branch 1\n");
		exit(1);
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
	a(100);
	return 0;
}