#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <wchar.h>
#include <locale.h>

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
    wchar_t pi = L'\u03c0'; /* Small pi symbol */
    wchar_t ae = L'\u2245'; /* Approximately equals symbol */
    double complex e = cexp(M_PI * I) + 1.0;
    setlocale(LC_CTYPE, "");
    printf("e ^ %lci + 1 = [%.16f, %.16f] %lc 0\n", pi, creal(e), cimag(e), ae);
    return 0;
}