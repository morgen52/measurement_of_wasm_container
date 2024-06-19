#include <stdio.h>
#include <stdlib.h>

unsigned long long sum35(unsigned long long limit)
{
    unsigned long long sum = 0;
    for (unsigned long long i = 0; i < limit; i++)
        if (!(i % 3) || !(i % 5))
            sum += i;
    return sum;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char **argv)
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
    unsigned long long limit;

    if (argc == 2)
        limit = strtoull(argv[1], NULL, 10);
    else
        limit = 1000;

    printf("%lld\n", sum35(limit));
    return 0;
}