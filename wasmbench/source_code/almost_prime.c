#include <stdio.h>

int kprime(int n, int k)
{
	int p, f = 0;
	for (p = 2; f < k && p*p <= n; p++)
		while (0 == n % p)
			n /= p, f++;

	return f + (n > 1) == k;
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
	int i, c, k;

	for (k = 1; k <= 5; k++) {
		printf("k = %d:", k);

		for (i = 2, c = 0; c < 10; i++)
			if (kprime(i, k)) {
				printf(" %d", i);
				c++;
			}

		putchar('\n');
	}

	return 0;
}