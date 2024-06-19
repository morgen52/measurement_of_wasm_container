#include <stdio.h>
 
typedef unsigned uint;
uint is_pern(uint n)
{
        uint c = 2693408940u; // int with all prime-th bits set
        while (n) c >>= 1, n &= (n - 1); // take out lowerest set bit one by one
        return c & 1;
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
        uint i, c;
        for (i = c = 0; c < 25; i++)
                if (is_pern(i))
                        printf("%u ", i), ++c;
        putchar('\n');
 
        for (i = 888888877u; i <= 888888888u; i++)
                if (is_pern(i))
                        printf("%u ", i);
        putchar('\n');
 
        return 0;
}