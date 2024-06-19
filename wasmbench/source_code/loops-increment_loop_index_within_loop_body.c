#include <stdio.h>
#include <locale.h>

#define LIMIT 42

int is_prime(long long n) {
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;
    long long d = 5;
    while (d * d <= n) {
        if (n % d == 0) return 0;
        d += 2;
        if (n % d == 0) return 0;
        d += 4;
    }
    return 1;
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
    long long i;
    int n;
    setlocale(LC_NUMERIC, "");
    for (i = LIMIT, n = 0; n < LIMIT; i++)
        if (is_prime(i)) {
            n++;
            printf("n = %-2d  %'19lld\n", n, i);
            i += i - 1;
        }
    return 0;
}