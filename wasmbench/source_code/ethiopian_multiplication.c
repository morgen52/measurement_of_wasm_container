#include <stdio.h>
#include <stdbool.h>

void halve(int *x) { *x >>= 1; }
void doublit(int *x)  { *x <<= 1; }
bool iseven(const int x) { return (x & 1) ==  0; }

int ethiopian(int plier,
	      int plicand, const bool tutor)
{
  int result=0;

  if (tutor)
    printf("ethiopian multiplication of %d by %d\n", plier, plicand);
  
  while(plier >= 1) {
    if ( iseven(plier) ) {
      if (tutor) printf("%4d %6d struck\n", plier, plicand);
    } else {
      if (tutor) printf("%4d %6d kept\n", plier, plicand);
      result += plicand;
    }
    halve(&plier); doublit(&plicand);
  }
  return result;
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
  printf("%d\n", ethiopian(17, 34, true));
  return 0;
}