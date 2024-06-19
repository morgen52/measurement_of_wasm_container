#include <stdio.h>
#include <stddef.h> /* for size_t */
#include <limits.h> /* for CHAR_BIT */

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
    int one = 1;

    /*
     * Best bet: size_t typically is exactly one word.
     */
    printf("word size = %d bits\n", (int)(CHAR_BIT * sizeof(size_t)));

    /*
     * Check if the least significant bit is located
     * in the lowest-address byte.
     */
    if (*(char *)&one)
        printf("little endian\n");
    else
        printf("big endian\n");
    return 0;
}