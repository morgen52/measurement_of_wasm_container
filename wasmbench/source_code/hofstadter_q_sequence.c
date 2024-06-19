#include <stdio.h>
#include <stdlib.h>

#define N 100000
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
	int i, flip, *q = (int*)malloc(sizeof(int) * N) - 1;

	q[1] = q[2] = 1;

	for (i = 3; i <= N; i++)
		q[i] = q[i - q[i - 1]] + q[i - q[i - 2]];
		
	for (i = 1; i <= 10; i++)
		printf("%d%c", q[i], i == 10 ? '\n' : ' ');

	printf("%d\n", q[1000]);

	for (flip = 0, i = 1; i < N; i++)
		flip += q[i] > q[i + 1];

	printf("flips: %d\n", flip);
	return 0;
}