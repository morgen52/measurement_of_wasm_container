#include <stdio.h>
#include <math.h>

double rms(double *v, int n)
{
  int i;
  double sum = 0.0;
  for(i = 0; i < n; i++)
    sum += v[i] * v[i];
  return sqrt(sum / n);
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
  double v[] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10.};
  printf("%f\n", rms(v, sizeof(v)/sizeof(double)));
  return 0;
}