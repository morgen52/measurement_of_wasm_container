#include <stdio.h>

int droot(long long int x, int base, int *pers)
{
	int d = 0;
	if (pers)
		for (*pers = 0; x >= base; x = d, (*pers)++)
			for (d = 0; x; d += x % base, x /= base);
	else if (x && !(d = x % (base - 1)))
			d = base - 1;

	return d;
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
	int i, d, pers;
	long long x[] = {627615, 39390, 588225, 393900588225LL};

	for (i = 0; i < 4; i++) {
		d = droot(x[i], 10, &pers);
		printf("%lld: pers %d, root %d\n", x[i], pers, d);
	}

	return 0;
}