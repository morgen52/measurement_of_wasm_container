#include <stdio.h>
#include <stdlib.h> // atoi()
#include <math.h> // pow()

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char* argv[])
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
  int i, count=0;
  double f, sum=0.0, prod=1.0, resum=0.0;

  for (i=1; i<argc; ++i) {
    f = atof(argv[i]);
    count++;
    sum += f;
    prod *= f;
    resum += (1.0/f);
  }
  //printf(" c:%d\n s:%f\n p:%f\n r:%f\n",count,sum,prod,resum);
  printf("Arithmetic mean = %f\n",sum/count);
  printf("Geometric mean = %f\n",pow(prod,(1.0/count)));
  printf("Harmonic mean = %f\n",count/resum);

  return 0;
}