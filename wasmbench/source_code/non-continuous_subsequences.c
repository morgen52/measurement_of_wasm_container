#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void binprint(unsigned int n, unsigned int m)
{
	char c[sizeof(n) * 8 + 1];
	int i = 0;
	while (m >>= 1)	c[i++] = n & m ? '#' : '-';
	c[i] = 0;
	puts(c);
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int c, char **v)
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
	unsigned int n, gap, left, right;
	if (c < 2 || ! (n = 1 << atoi(v[1]))) n = 16;

	for (gap = 2; gap < n; gap <<= 1)
		for (left = gap << 1; left < n; left |= left << 1)
			for (right = 1; right < gap; right++)
				binprint(left | right, n);

	return 0;
}