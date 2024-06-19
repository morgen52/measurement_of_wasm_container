#include <stdio.h>
#include <stdlib.h>
 
#define valid(i, j) 0 <= i && i < m && 0 <= j && j < n && !s[i][j]
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int c, char **v)
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
	int i, j, m = 0, n = 0;
 
	/* default size: 5 */
	if (c >= 2) m = atoi(v[1]);
	if (c >= 3) n = atoi(v[2]);
	if (m <= 0) m = 5;
	if (n <= 0) n = m;
 
	int **s = calloc(1, sizeof(int *) * m + sizeof(int) * m * n);
	s[0] = (int*)(s + m);
	for (i = 1; i < m; i++) s[i] = s[i - 1] + n;
 
	int dx = 1, dy = 0, val = 0, t;
	for (i = j = 0; valid(i, j); i += dy, j += dx ) {
		for (; valid(i, j); j += dx, i += dy)
			s[i][j] = ++val;
 
		j -= dx; i -= dy;
		t = dy; dy = dx; dx = -t;
	}

	for (t = 2; val /= 10; t++);

	for(i = 0; i < m; i++)
		for(j = 0; j < n || !putchar('\n'); j++)
			printf("%*d", t, s[i][j]);

	return 0;
}