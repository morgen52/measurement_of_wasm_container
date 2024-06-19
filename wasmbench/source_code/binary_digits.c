#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *bin(uint32_t x);

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
    for (size_t i = 0; i < 20; i++) {
        char *binstr = bin(i);
        printf("%s\n", binstr);
        free(binstr);
    }
}

char *bin(uint32_t x)
{
    size_t bits = (x == 0) ? 1 : log10((double) x)/log10(2) + 1;
    char *ret = malloc((bits + 1) * sizeof (char));
    for (size_t i = 0; i < bits ; i++) {
       ret[bits - i - 1] = (x & 1) ? '1' : '0';
       x >>= 1;
    }
    ret[bits] = '\0';
    return ret;
}