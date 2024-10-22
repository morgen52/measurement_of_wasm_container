#include <stdio.h>
#include <math.h>

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
	double a, c, s, PI2 = atan2(1, 1) * 8;
	int n, i;

	for (n = 1; n < 10; n++) for (i = 0; i < n; i++) {
		c = s = 0;
		if (!i )		c =  1;
		else if(n == 4 * i)	s =  1;
		else if(n == 2 * i)	c = -1;
		else if(3 * n == 4 * i)	s = -1;
		else
			a = i * PI2 / n, c = cos(a), s = sin(a);

		if (c) printf("%.2g", c);
		printf(s == 1 ? "i" : s == -1 ? "-i" : s ? "%+.2gi" : "", s);
		printf(i == n - 1 ?"\n":",  ");
	}

	return 0;
}