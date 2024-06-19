#include <stdio.h>
#include <float.h>

double pow_ (double x, int e) {
    int i;
    double r = 1;
    for (i = 0; i < e; i++) {
        r *= x;
    }
    return r;
}

double root (int n, double x) {
    double d, r = 1;
    if (!x) {
        return 0;
    }
    if (n < 1 || (x < 0 && !(n&1))) {
        return 0.0 / 0.0; /* NaN */
    }
    do {
        d = (x / pow_(r, n - 1) - r) / n;
        r += d;
    }
    while (d >= DBL_EPSILON * 10 || d <= -DBL_EPSILON * 10);
    return r;
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
    int n = 15;
    double x = pow_(-3.14159, 15);
    printf("root(%d, %g) = %g\n", n, x, root(n, x));
    return 0;
}
