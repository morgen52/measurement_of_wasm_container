#include <stdio.h>
#include <stdbool.h>

bool a(bool in)
{
  printf("I am a\n");
  return in;
}

bool b(bool in)
{
  printf("I am b\n");
  return in;
}

#define TEST(X,Y,O)						\
  do {								\
    x = a(X) O b(Y);						\
    printf(#X " " #O " " #Y " = %s\n\n", x ? "true" : "false");	\
  } while(false);

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
  bool x;

  TEST(false, true, &&); // b is not evaluated
  TEST(true, false, ||); // b is not evaluated
  TEST(true, false, &&); // b is evaluated
  TEST(false, false, ||); // b is evaluated 

  return 0;
}