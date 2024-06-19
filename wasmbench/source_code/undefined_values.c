#include <stdio.h>
#include <stdlib.h>

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
	int junk, *junkp;

	/* Print an unitialized variable! */
	printf("junk: %d\n", junk);

	/* Follow a pointer to unitialized memory! */
	junkp = malloc(sizeof *junkp);
	if (junkp)
		printf("*junkp: %d\n", *junkp);
	return 0;
}