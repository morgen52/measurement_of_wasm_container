#include <stdio.h>

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
	puts(	"%!PS-Adobe-3.0 EPSF\n"
		"%%BoundingBox: -10 -10 400 565\n"
		"/a{0 0 moveto 0 .4 translate 0 0 lineto stroke -1 1 scale}def\n"
		"/b{a 90 rotate}def");

	char i;
	for (i = 'c'; i <= 'z'; i++)
		printf("/%c{%c %c}def\n", i, i-1, i-2);

	puts("0 setlinewidth z showpage\n%%EOF");

	return 0;
}