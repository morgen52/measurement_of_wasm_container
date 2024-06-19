#include <stdio.h>

int is_leap_year(int year)
{
    return (!(year % 4) && year % 100 || !(year % 400)) ? 1 : 0;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main()
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
    int test_case[] = {1900, 1994, 1996, 1997, 2000}, key, end, year;
    for (key = 0, end = sizeof(test_case)/sizeof(test_case[0]); key < end; ++key) {
        year = test_case[key];
        printf("%d is %sa leap year.\n", year, (is_leap_year(year) == 1 ? "" : "not "));
    }
}