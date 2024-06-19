#include <math.h>
#include <stdio.h>
#include <assert.h>

int nonsqr(int n) {
    return n + (int)(0.5 + sqrt(n));
    /* return n + (int)round(sqrt(n)); in C99 */
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
    int i;
    
    /* first 22 values (as a list) has no squares: */
    for (i = 1; i < 23; i++)
        printf("%d ", nonsqr(i));
    printf("\n");
    
    /* The following check shows no squares up to one million: */
    for (i = 1; i < 1000000; i++) {
        double j = sqrt(nonsqr(i));
        assert(j != floor(j));
    }
    return 0;
}