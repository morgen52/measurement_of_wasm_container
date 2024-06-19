#include <stdio.h>

static int digsum(int n)
{
    int sum = 0;
    do { sum += n % 10; } while (n /= 10);
    return sum;
}

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
    int n, done, found;

    for (n = 1, done = found = 0; !done; ++n) {
        if (n % digsum(n) == 0) {
            if (found++ < 20) printf("%d ", n);
            if (n > 1000) done = printf("\n%d\n", n);
        }
    }

    return 0;
}