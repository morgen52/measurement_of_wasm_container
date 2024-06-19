#include <stdio.h>
#include <limits.h>

typedef unsigned long long ull;
#define N (sizeof(ull) * CHAR_BIT)
#define B(x) (1ULL << (x))

void evolve(ull state, int rule)
{
	int i, p, q, b;

	for (p = 0; p < 10; p++) {
		for (b = 0, q = 8; q--; ) {
			ull st = state;
			b |= (st&1) << q;

			for (state = i = 0; i < N; i++)
				if (rule & B(7 & (st>>(i-1) | st<<(N+1-i))))
					state |= B(i);
		}
		printf(" %d", b);
	}
	putchar('\n');
	return;
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
	evolve(1, 30);
	return 0;
}