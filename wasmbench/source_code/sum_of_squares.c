#include <stdio.h>

double squaredsum(double *l, int e)
{
   int i; double sum = 0.0;
   for(i = 0 ; i < e ; i++) sum += l[i]*l[i];
   return sum;
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
   double list[6] = {3.0, 1.0, 4.0, 1.0, 5.0, 9.0};
   
   printf("%lf\n", squaredsum(list, 6));
   printf("%lf\n", squaredsum(list, 0));
   /* the same without using a real list as if it were 0-element long */
   printf("%lf\n", squaredsum(NULL, 0));
   return 0;
}