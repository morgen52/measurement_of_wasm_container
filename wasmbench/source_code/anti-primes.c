#include <stdio.h>

int countDivisors(int n) {
    int i, count;
    if (n < 2) return 1;
    count = 2; // 1 and n
    for (i = 2; i <= n/2; ++i) {
        if (n%i == 0) ++count;
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
    int n, d, maxDiv = 0, count = 0;
    printf("The first 20 anti-primes are:\n");
    for (n = 1; count < 20; ++n) {
        d = countDivisors(n); 
        if (d > maxDiv) {
            printf("%d ", n);
            maxDiv = d;
            count++;
        }
    }
    printf("\n"); 
    return 0;
}