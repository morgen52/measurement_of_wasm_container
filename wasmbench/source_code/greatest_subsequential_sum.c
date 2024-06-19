#include "stdio.h"

typedef struct Range {
    int start, end, sum;
} Range;

Range maxSubseq(const int sequence[], const int len) {
    int maxSum = 0, thisSum = 0, i = 0;
    int start = 0, end = -1, j;

    for (j = 0; j < len; j++) {
        thisSum += sequence[j];
        if (thisSum < 0) {
            i = j + 1;
            thisSum = 0;
        } else if (thisSum > maxSum) {
            maxSum = thisSum;
            start = i;
            end   = j;
        }
    }

    Range r;
    if (start <= end && start >= 0 && end >= 0) {
        r.start = start;
        r.end = end + 1;
        r.sum = maxSum;
    } else {
        r.start = 0;
        r.end = 0;
        r.sum = 0;
    }
    return r;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char **argv) {
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
    int a[] = {-1 , -2 , 3 , 5 , 6 , -2 , -1 , 4 , -4 , 2 , -1};
    int alength = sizeof(a)/sizeof(a[0]);

    Range r = maxSubseq(a, alength);
    printf("Max sum = %d\n", r.sum);
    int i;
    for (i = r.start; i < r.end; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}