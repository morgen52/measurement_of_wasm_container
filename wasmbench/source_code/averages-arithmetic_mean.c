#include <stdio.h>

double mean(double *v, int len)
{
	double sum = 0;
	int i;
	for (i = 0; i < len; i++)
		sum += v[i];
	return sum / len;
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
	double v[] = {1, 2, 2.718, 3, 3.142};
	int i, len;
	for (len = 5; len >= 0; len--) {
		printf("mean[");
		for (i = 0; i < len; i++)
			printf(i ? ", %g" : "%g", v[i]);
		printf("] = %g\n", mean(v, len));
	}

	return 0;
}