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
	int i, j, n = 12;
 
	for (j = 1; j <= n; j++) printf("%3d%c", j, j != n ? ' ' : '\n');
	for (j = 0; j <= n; j++) printf(j != n ? "----" : "+\n");

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf(j < i ? "    " : "%3d ", i * j);
                printf("| %d\n", i);
        }
 
	return 0;
}