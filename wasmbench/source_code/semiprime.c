#include <stdio.h>

int semiprime(int n)
{
	int p, f = 0;
	for (p = 2; f < 2 && p*p <= n; p++)
		while (0 == n % p)
			n /= p, f++;

	return f + (n > 1) == 2;
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
	int i;
	for (i = 2; i < 100; i++)
		if (semiprime(i)) printf(" %d", i);
	putchar('\n');

	return 0;
}