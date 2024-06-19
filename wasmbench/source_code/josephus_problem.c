#include <stdio.h>

// m-th on the reversed kill list; m = 0 is final survivor
int jos(int n, int k, int m) {
	int a;
	for (a = m + 1; a <= n; a++)
		m = (m + k) % a;
	return m;
}

typedef unsigned long long xint;

// same as jos(), useful if n is large and k is not
xint jos_large(xint n, xint k, xint m) {
	if (k <= 1) return n - m - 1;

	xint a = m;
	while (a < n) {
		xint q = (a - m + k - 2) / (k - 1);

		if (a + q > n)	q = n - a;
		else if (!q)	q = 1;

		m = (m + q * k) % (a += q);
	}

	return m;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(void) {
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
	xint n, k, i;

	n = 41;
	k = 3;
	printf("n = %llu, k = %llu, final survivor: %d\n", n, k, jos(n, k, 0));

	n = 9876543210987654321ULL;
	k = 12031;
	printf("n = %llu, k = %llu, three survivors:", n, k);

	for (i = 3; i--; )
		printf(" %llu", jos_large(n, k, i));
	putchar('\n');

	return 0;
}