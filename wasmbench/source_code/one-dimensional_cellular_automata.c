#include <stdio.h>
#include <string.h>

char trans[] = "___#_##_";

#define v(i) (cell[i] != '_')
int evolve(char cell[], char backup[], int len)
{
	int i, diff = 0;

	for (i = 0; i < len; i++) {
		/* use left, self, right as binary number bits for table index */
		backup[i] = trans[ v(i-1) * 4 + v(i) * 2 + v(i + 1) ];
		diff += (backup[i] != cell[i]);
	}

	strcpy(cell, backup);
	return diff;
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
	char	c[] = "_###_##_#_#_#_#__#__\n",
		b[] = "____________________\n";

	do { printf(c + 1); } while (evolve(c + 1, b + 1, sizeof(c) - 3));
	return 0;
}