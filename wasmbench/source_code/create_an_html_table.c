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
	int i;
	printf("<table style=\"text-align:center; border: 1px solid\"><th></th>"
		"<th>X</th><th>Y</th><th>Z</th>");
	for (i = 0; i < 4; i++) {
		printf("<tr><th>%d</th><td>%d</td><td>%d</td><td>%d</td></tr>", i,
			rand() % 10000, rand() % 10000, rand() % 10000);
	}
	printf("</table>");

	return 0;
}