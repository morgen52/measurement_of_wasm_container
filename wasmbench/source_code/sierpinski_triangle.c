#include <stdio.h>
 
#define SIZE (1 << 4)
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
	int x, y, i;
	for (y = SIZE - 1; y >= 0; y--, putchar('\n')) {
		for (i = 0; i < y; i++) putchar(' ');
		
		for (x = 0; x + y < SIZE; x++)
			printf((x & y) ? "  " : "* ");
	}
	return 0;
}