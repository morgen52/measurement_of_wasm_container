#include <stdio.h>

int i;
double sum(int *i, int lo, int hi, double (*term)()) {
    double temp = 0;
    for (*i = lo; *i <= hi; (*i)++)
        temp += term();
    return temp;
}

double term_func() { return 1.0 / i; }

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main () {
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
    printf("%f\n", sum(&i, 1, 100, term_func));
    return 0;
}