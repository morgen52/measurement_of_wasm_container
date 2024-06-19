#include <stdio.h>

#define DEBUG_INT(x) printf( #x " at line %d\nresult: %d\n\n", __LINE__, x)

int add(int x, int y) {
  int result = x + y;
  DEBUG_INT(x);
  DEBUG_INT(y);
  DEBUG_INT(result);
  DEBUG_INT(result+1);
  return result;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main() {
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
  add(2, 7);
  return 0;
}