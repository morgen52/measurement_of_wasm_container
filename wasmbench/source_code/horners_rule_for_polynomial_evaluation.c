#include <stdio.h>

double horner(double *coeffs, int s, double x)
{
  int i;
  double res = 0.0;
  
  for(i=s-1; i >= 0; i--)
  {
    res = res * x + coeffs[i];
  }
  return res;
}


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
  double coeffs[] = { -19.0, 7.0, -4.0, 6.0 };
  
  printf("%5.1f\n", horner(coeffs, sizeof(coeffs)/sizeof(double), 3.0));
  return 0;
}