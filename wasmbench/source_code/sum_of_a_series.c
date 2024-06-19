#include <stdio.h>

double Invsqr(double n)
{
	return 1 / (n*n);
}

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
	int i, start = 1, end = 1000;
	double sum = 0.0;
	
	for( i = start; i <= end; i++)
		sum += Invsqr((double)i);           
	
	printf("%16.14f\n", sum);
	
	return 0;
}