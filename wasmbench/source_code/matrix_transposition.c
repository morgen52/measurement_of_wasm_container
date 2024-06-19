#include <stdio.h>

void transpose(void *dest, void *src, int src_h, int src_w)
{
	int i, j;
	double (*d)[src_h] = dest, (*s)[src_w] = src;
	for (i = 0; i < src_h; i++)
		for (j = 0; j < src_w; j++)
			d[j][i] = s[i][j];
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
	int i, j;
	double a[3][5] = {{ 0, 1, 2, 3, 4 },
			  { 5, 6, 7, 8, 9 },
			  { 1, 0, 0, 0, 42}};
	double b[5][3];
	transpose(b, a, 3, 5);

	for (i = 0; i < 5; i++)
		for (j = 0; j < 3; j++)
			printf("%g%c", b[i][j], j == 2 ? '\n' : ' ');
	return 0;
}