#include <stdio.h>
#include <stdlib.h>

/* let us declare our functions; indeed here we need
   really only M declaration, so that F can "see" it
   and the compiler won't complain with a warning */
int F(const int n);
int M(const int n);

int F(const int n)
{
  return (n == 0) ? 1 : n - M(F(n - 1));
}

int M(const int n)
{
  return (n == 0) ? 0 : n - F(M(n - 1));
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
  int i;
  for (i = 0; i < 20; i++)
    printf("%2d ", F(i));
  printf("\n");
  for (i = 0; i < 20; i++)
    printf("%2d ", M(i));
  printf("\n");
  return EXIT_SUCCESS;
}