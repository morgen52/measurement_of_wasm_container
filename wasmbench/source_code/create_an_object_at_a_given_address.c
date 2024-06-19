#include <stdio.h>

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
  int intspace;
  int *address;

  address = &intspace; // address = 0x100;
  *address = 65535;
  printf("%p: %08x (=%08x)\n", address, *address, intspace);
  // likely we must be worried about endianness, e.g.
  *((char*)address) = 0x00;
  *((char*)address+1) = 0x00;
  *((char*)address+2) = 0xff;
  *((char*)address+3) = 0xff; // if sizeof(int) == 4!
  // which maybe is not the best way of writing 32 bit values...
  printf("%p: %08x (=%08x)\n", address, *address, intspace);
  return 0;
}