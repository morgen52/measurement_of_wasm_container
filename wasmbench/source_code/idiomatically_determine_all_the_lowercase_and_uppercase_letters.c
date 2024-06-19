#include <stdio.h>

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char const *argv[]) {
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
  for (char c = 0x41; c < 0x5b; c ++) putchar(c);
  putchar('\n');
  for (char c = 0x61; c < 0x7b; c ++) putchar(c);
  putchar('\n');
  return 0;
}