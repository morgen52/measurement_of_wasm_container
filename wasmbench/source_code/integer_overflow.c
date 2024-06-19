#include <stdio.h>

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main (int argc, char *argv[])
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
  printf("Signed 32-bit:\n");
  printf("%d\n", -(-2147483647-1));
  printf("%d\n", 2000000000 + 2000000000);
  printf("%d\n", -2147483647 - 2147483647);
  printf("%d\n", 46341 * 46341);
  printf("%d\n", (-2147483647-1) / -1);
  printf("Signed 64-bit:\n");
  printf("%ld\n", -(-9223372036854775807-1));
  printf("%ld\n", 5000000000000000000+5000000000000000000);
  printf("%ld\n", -9223372036854775807 - 9223372036854775807);
  printf("%ld\n", 3037000500 * 3037000500);
  printf("%ld\n", (-9223372036854775807-1) / -1);
  printf("Unsigned 32-bit:\n");
  printf("%u\n", -4294967295U);
  printf("%u\n", 3000000000U + 3000000000U);
  printf("%u\n", 2147483647U - 4294967295U);
  printf("%u\n", 65537U * 65537U);
  printf("Unsigned 64-bit:\n");
  printf("%lu\n", -18446744073709551615LU);
  printf("%lu\n", 10000000000000000000LU + 10000000000000000000LU);
  printf("%lu\n", 9223372036854775807LU - 18446744073709551615LU);
  printf("%lu\n", 4294967296LU * 4294967296LU);
  return 0;
}