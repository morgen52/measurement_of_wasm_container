#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int catcmp(const void *a, const void *b)
{
	char ab[32], ba[32];
	sprintf(ab, "%d%d", *(int*)a, *(int*)b);
	sprintf(ba, "%d%d", *(int*)b, *(int*)a);
	return strcmp(ba, ab);
}

void maxcat(int *a, int len)
{
	int i;
	qsort(a, len, sizeof(int), catcmp);
	for (i = 0; i < len; i++)
		printf("%d", a[i]);
	putchar('\n');
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(void)
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
	int x[] = {1, 34, 3, 98, 9, 76, 45, 4};
	int y[] = {54, 546, 548, 60};

	maxcat(x, sizeof(x)/sizeof(x[0]));
	maxcat(y, sizeof(y)/sizeof(y[0]));

	return 0;
}