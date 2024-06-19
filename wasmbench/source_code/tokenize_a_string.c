#include<string.h>
#include<stdio.h>
#include<stdlib.h>

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
	char *a[5];
	const char *s="Hello,How,Are,You,Today";
	int n=0, nn;

	char *ds=strdup(s);

	a[n]=strtok(ds, ",");
	while(a[n] && n<4) a[++n]=strtok(NULL, ",");

	for(nn=0; nn<=n; ++nn) printf("%s.", a[nn]);
	putchar('\n');

	free(ds);

	return 0;
}