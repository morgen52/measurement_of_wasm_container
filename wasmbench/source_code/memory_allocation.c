#include <stdlib.h>

/* size of "members", in bytes */
#define SIZEOF_MEMB (sizeof(int))
#define NMEMB 100

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
  int *ints = malloc(SIZEOF_MEMB*NMEMB);
  /* realloc can be used to increase or decrease an already
     allocated memory (same as malloc if ints is NULL) */
  ints = realloc(ints, sizeof(int)*(NMEMB+1));
  /* calloc set the memory to 0s */
  int *int2 = calloc(NMEMB, SIZEOF_MEMB);
  /* all use the same free */
  free(ints); free(int2);
  return 0;
}