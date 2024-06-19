#include <stdio.h>
#include <stdlib.h>

long long c[100];

void coef(int n)
{
	int i, j;

	if (n < 0 || n > 63) abort(); // gracefully deal with range issue

	for (c[i=0] = 1; i < n; c[0] = -c[0], i++)
		for (c[1 + (j=i)] = 1; j > 0; j--)
			c[j] = c[j-1] - c[j];
}

int is_prime(int n)
{
	int i;

	coef(n);
	c[0] += 1, c[i=n] -= 1;
	while (i-- && !(c[i] % n));

	return i < 0;
}

void show(int n)
{
	do printf("%+lldx^%d", c[n], n); while (n--);
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
	int n;

	for (n = 0; n < 10; n++) {
		coef(n);
		printf("(x-1)^%d = ", n);
		show(n);
		putchar('\n');
	}

	printf("\nprimes (never mind the 1):");
	for (n = 1; n <= 63; n++)
		if (is_prime(n))
			printf(" %d", n);

	putchar('\n');
	return 0;
}