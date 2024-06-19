#include <stdio.h>

void pascaltriangle(unsigned int n)
{
  unsigned int c, i, j, k;

  for(i=0; i < n; i++) {
    c = 1;
    for(j=1; j <= 2*(n-1-i); j++) printf(" ");
    for(k=0; k <= i; k++) {
      printf("%3d ", c);
      c = c * (i-k)/(k+1);
    }
    printf("\n");
  }
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
  pascaltriangle(8);
  return 0;
}