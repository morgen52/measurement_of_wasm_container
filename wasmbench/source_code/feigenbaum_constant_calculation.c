#include <stdio.h>

void feigenbaum() {
    int i, j, k, max_it = 13, max_it_j = 10;
    double a, x, y, d, a1 = 1.0, a2 = 0.0, d1 = 3.2;
    printf(" i       d\n");
    for (i = 2; i <= max_it; ++i) {
        a = a1 + (a1 - a2) / d1;
        for (j = 1; j <= max_it_j; ++j) {
            x = 0.0;
            y = 0.0;
            for (k = 1; k <= 1 << i; ++k) {
                 y = 1.0 - 2.0 * y * x;
                 x = a - x * x;
            }
            a -= x / y;
        }
        d = (a1 - a2) / (a - a1);
        printf("%2d    %.8f\n", i, d);
        d1 = d;
        a2 = a1;
        a1 = a;
    }
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
    feigenbaum();
    return 0;
}