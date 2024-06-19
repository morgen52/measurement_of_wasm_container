#include <stdio.h>

int SumDigits(unsigned long long n, const int base) {
    int sum = 0;
    for (; n; n /= base)
    	sum += n % base;
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
    printf("%d %d %d %d %d\n",
        SumDigits(1, 10),
        SumDigits(12345, 10),
        SumDigits(123045, 10),
        SumDigits(0xfe, 16),
        SumDigits(0xf0e, 16) );
    return 0;
}