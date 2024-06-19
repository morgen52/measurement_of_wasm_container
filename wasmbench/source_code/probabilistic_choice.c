#include <stdio.h>
#include <stdlib.h>

/* pick a random index from 0 to n-1, according to probablities listed
   in p[] which is assumed to have a sum of 1. The values in the probablity
   list matters up to the point where the sum goes over 1 */
int rand_idx(double *p, int n)
{
	double s = rand() / (RAND_MAX + 1.0);
	int i;
	for (i = 0; i < n - 1 && (s -= p[i]) >= 0; i++);
	return i;
}

#define LEN 8
#define N 1000000
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main()
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
	const char *names[LEN] = { "aleph", "beth", "gimel", "daleth",
			  "he", "waw", "zayin", "heth" };
	double s, p[LEN] = { 1./5, 1./6, 1./7, 1./8, 1./9, 1./10, 1./11, 1e300 };
	int i, count[LEN] = {0};

	for (i = 0; i < N; i++) count[rand_idx(p, LEN)] ++;

	printf("  Name  Count    Ratio Expected\n");
	for (i = 0, s = 1; i < LEN; s -= p[i++])
		printf("%6s%7d %7.4f%% %7.4f%%\n",
			names[i], count[i],
			(double)count[i] / N * 100,
			((i < LEN - 1) ? p[i] : s) * 100);

	return 0;
}