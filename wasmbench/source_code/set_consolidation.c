#include <stdio.h>

#define s(x) (1U << ((x) - 'A'))

typedef unsigned int bitset;

int consolidate(bitset *x, int len)
{
	int i, j;
	for (i = len - 2; i >= 0; i--)
		for (j = len - 1; j > i; j--)
			if (x[i] & x[j])
				x[i] |= x[j], x[j] = x[--len];
	return len;
}

void show_sets(bitset *x, int len)
{
	bitset b;
	while(len--) {
		for (b = 'A'; b <= 'Z'; b++)
			if (x[len] & s(b)) printf("%c ", b);
		putchar('\n');
	}
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
	bitset x[] = { s('A') | s('B'), s('C') | s('D'), s('B') | s('D'),
			s('F') | s('G') | s('H'), s('H') | s('I') | s('K') };

	int len = sizeof(x) / sizeof(x[0]);

	puts("Before:"); show_sets(x, len);
	puts("\nAfter:"); show_sets(x, consolidate(x, len));
	return 0;
}