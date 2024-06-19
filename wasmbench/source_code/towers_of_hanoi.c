#include <stdio.h>

void move(int n, int from, int via, int to)
{
  if (n > 1) {
    move(n - 1, from, to, via);
    printf("Move disk from pole %d to pole %d\n", from, to);
    move(n - 1, via, from, to);
  } else {
    printf("Move disk from pole %d to pole %d\n", from, to);
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
  move(4, 1,2,3);
  return 0;
}