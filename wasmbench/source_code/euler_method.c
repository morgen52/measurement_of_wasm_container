#include <stdio.h>
#include <math.h>

typedef double (*deriv_f)(double, double);
#define FMT " %7.3f"

void ivp_euler(deriv_f f, double y, int step, int end_t)
{
	int t = 0;

	printf(" Step %2d: ", (int)step);
	do {
		if (t % 10 == 0) printf(FMT, y);
		y += step * f(t, y);
	} while ((t += step) <= end_t);
	printf("\n");
}

void analytic()
{
	double t;
	printf("    Time: ");
	for (t = 0; t <= 100; t += 10) printf(" %7g", t);
	printf("\nAnalytic: ");

	for (t = 0; t <= 100; t += 10)
		printf(FMT, 20 + 80 * exp(-0.07 * t));
	printf("\n");
}

double cooling(double t, double temp)
{
	return -0.07 * (temp - 20);
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
	analytic();
	ivp_euler(cooling, 100, 2, 100);
	ivp_euler(cooling, 100, 5, 100);
	ivp_euler(cooling, 100, 10, 100);

	return 0;
}