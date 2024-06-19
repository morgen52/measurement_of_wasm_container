#include <stdio.h>
#include <stdlib.h>

int dot_product(int *, int *, size_t);

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
        int a[3] = {1, 3, -5};
        int b[3] = {4, -2, -1};

        printf("%d\n", dot_product(a, b, sizeof(a) / sizeof(a[0])));

        return EXIT_SUCCESS;
}

int
dot_product(int *a, int *b, size_t n)
{
        int sum = 0;
        size_t i;

        for (i = 0; i < n; i++) {
                sum += a[i] * b[i];
        }

        return sum;
}