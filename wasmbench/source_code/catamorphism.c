#include <stdio.h>

typedef int (*intFn)(int, int);

int reduce(intFn fn, int size, int *elms)
{
    int i, val = *elms;
    for (i = 1; i < size; ++i)
        val = fn(val, elms[i]);
    return val;
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

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
    int nums[] = {1, 2, 3, 4, 5};
    printf("%d\n", reduce(add, 5, nums));
    printf("%d\n", reduce(sub, 5, nums));
    printf("%d\n", reduce(mul, 5, nums));
    return 0;
}