#include <stdio.h>
#include <values.h>
#include <math.h>

char * bits(double v) {
	static char s[sizeof(double) * (CHARBITS + 1)];
	int n, i, j;
	unsigned char *c = (void*)&v;
	for (i = n = 0; i < sizeof(double); i++) {
		for (j = 1 << (CHARBITS - 1); j; j >>= 1)
			s[n++] = (c[i] & j) ? '1' : '.';
		s[n++] = ' ';
	}
	s[n-1] = 0;
	return s;
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
	double x[] = {
		1.0, -1.0, 1.0/256, 0.0, // "normal" values
		-0.0, INFINITY, -INFINITY, NAN, -NAN, // special
		DBL_MAX, DBL_MIN // not required by task
	};
	int i;

	for (i = 0; i < sizeof(x) / sizeof(x[0]); i++)
		printf("%s | %g\n", bits(x[i]), x[i]);

	return 0;
}