#include <stdio.h>
#include <math.h>

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
    int n = 1, count = 0, sq, cr;
    for ( ; count < 30; ++n) {
        sq = n * n;
        cr = (int)cbrt((double)sq);
        if (cr * cr * cr != sq) {
            count++;
            printf("%d\n", sq);
        }
        else {
            printf("%d is square and cube\n", sq);
        }
    }
    return 0;
}