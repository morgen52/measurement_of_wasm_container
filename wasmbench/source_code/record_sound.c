#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void * record(size_t bytes)
{
	int fd;
	if (-1 == (fd = open("/dev/dsp", O_RDONLY))) return 0;
	void *a = malloc(bytes);
	read(fd, a, bytes);
	close(fd);
	return a;
}

int play(void *buf, size_t len)
{
	int fd;
	if (-1 == (fd = open("/dev/dsp", O_WRONLY))) return 0;
	write(fd, buf, len);
	close(fd);
	return 1;
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
	void *p = record(65536);
	play(p, 65536);
	return 0;
}