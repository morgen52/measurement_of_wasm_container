#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, const char *argv[]) {
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
  const int max = 1000;
  int *a = malloc(max * sizeof(int));
  for (int n = 0; n < max - 1; n ++) {
    for (int m = n - 1; m >= 0; m --) {
      if (a[m] == a[n]) {
        a[n+1] = n - m;
        break;
      }
    }
  }

  printf("The first ten terms of the Van Eck sequence are:\n");
  for (int i = 0; i < 10; i ++) printf("%d ", a[i]);
  printf("\n\nTerms 991 to 1000 of the sequence are:\n");
  for (int i = 990; i < 1000; i ++) printf("%d ", a[i]);
  putchar('\n');

  return 0;
}