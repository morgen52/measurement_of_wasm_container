#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ham;

size_t alloc = 0, n = 1;
ham *q = 0;

void qpush(ham h)
{
	int i, j;
	if (alloc <= n) {
		alloc = alloc ? alloc * 2 : 16;
		q = realloc(q, sizeof(ham) * alloc);
	}

	for (i = n++; (j = i/2) && q[j] > h; q[i] = q[j], i = j);
	q[i] = h;
}

ham qpop()
{
	int i, j;
	ham r, t;
	/* outer loop for skipping duplicates */
	for (r = q[1]; n > 1 && r == q[1]; q[i] = t) {
		/* inner loop is the normal down heap routine */
		for (i = 1, t = q[--n]; (j = i * 2) < n;) {
			if (j + 1 < n && q[j] > q[j+1]) j++;
			if (t <= q[j]) break;
			q[i] = q[j], i = j;
		}
	}

	return r;
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
	int i;
	ham h;

	for (qpush(i = 1); i <= 1691; i++) {
		/* takes smallest value, and queue its multiples */
		h = qpop();
		qpush(h * 2);
		qpush(h * 3);
		qpush(h * 5);

		if (i <= 20 || i == 1691)
			printf("%6d: %llu\n", i, h);
	}

	/* free(q); */
	return 0;
}