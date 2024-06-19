#include <stdio.h>

typedef unsigned int uint;

/* the sequence, 0-th member is 0 */
uint f(uint n)
{
	return n < 2 ? n : (n&1) ? f(n/2) + f(n/2 + 1) : f(n/2);
}

uint gcd(uint a, uint b)
{
	return a ? a < b ? gcd(b%a, a) : gcd(a%b, b) : b;
}

void find(uint from, uint to)
{
	do {
		uint n;
		for (n = 1; f(n) != from ; n++);
		printf("%3u at Stern #%u.\n", from, n);
	} while (++from <= to);
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
	uint n;
	for (n = 1; n < 16; n++) printf("%u ", f(n));
	puts("are the first fifteen.");

	find(1, 10);
	find(100, 0);

	for (n = 1; n < 1000 && gcd(f(n), f(n+1)) == 1; n++);
	printf(n == 1000 ? "All GCDs are 1.\n" : "GCD of #%d and #%d is not 1", n, n+1);

	return 0;
}