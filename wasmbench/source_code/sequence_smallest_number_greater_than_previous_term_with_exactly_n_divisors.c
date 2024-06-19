#include <stdio.h>

#define MAX 15

int count_divisors(int n) {
    int i, count = 0;
    for (i = 1; i * i <= n; ++i) {
        if (!(n % i)) {
            if (i == n / i)
                count++;
            else
                count += 2;
        }
    }
    return count;
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
    int i, next = 1;
    printf("The first %d terms of the sequence are:\n", MAX);
    for (i = 1; next <= MAX; ++i) {
        if (next == count_divisors(i)) {           
            printf("%d ", i);
            next++;
        }
    }
    printf("\n");
    return 0;
}