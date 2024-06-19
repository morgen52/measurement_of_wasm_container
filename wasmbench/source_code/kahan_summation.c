#include <stdio.h>
#include <stdlib.h>

float epsilon() {
    float eps = 1.0f;
    while (1.0f + eps != 1.0f) eps /= 2.0f;
    return eps;
}

float kahanSum(float *nums, int count) {
    float sum = 0.0f;
    float c = 0.0f;
    float t, y;
    int i;
    for (i = 0; i < count; ++i) {
        y = nums[i] - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
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
    float a = 1.0f;
    float b = epsilon();
    float c = -b;
    float fa[3];

    fa[0] = a;
    fa[1] = b;
    fa[2] = c;

    printf("Epsilon     = %0.12f\n", b);
    printf("(a + b) + c = %0.12f\n", (a + b) + c);
    printf("Kahan sum   = %0.12f\n", kahanSum(fa, 3));

    return 0;
}