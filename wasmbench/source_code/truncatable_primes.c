#include <stdio.h>

#define MAXN 1000000
int maxl, maxr;

int is_prime(int n)
{
	int p;
	if (n % 3 == 0) return 0;

	for (p = 6; p * p <= n; p += 6)
		if (!(n % (p + 1) && n % (p + 5)))
			return 0;
	return 1;
}

void left(int n, int tens)
{
	int i, nn;

	if (n > maxl) maxl = n;
	if (n < MAXN / 10)
		for (tens *= 10, i = 1; i < 10; i++)
			if (is_prime(nn = i * tens + n))
				left(nn, tens);
}

void right(int n)
{
	int i, nn;
	static int d[] = {1,3,7,9};

	if (n > maxr) maxr = n;
	if (n < MAXN / 10)
		for (i = 1; i < 4; i++)
			if (is_prime(nn = n * 10 + d[i])) right(nn);
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
	left(3, 1); left(7, 1);
	right(3); right(5); right(7);

	printf("%d %d\n", maxl, maxr);

	return 0;
}