#include <stdio.h>

int circle_sort_inner(int *start, int *end)
{
	int *p, *q, t, swapped;

	if (start == end) return 0;

	// funny "||" on next line is for the center element of odd-lengthed array
	for (swapped = 0, p = start, q = end; p<q || (p==q && ++q); p++, q--)
		if (*p > *q)
			t = *p, *p = *q, *q = t, swapped = 1;

	// q == p-1 at this point
	return swapped | circle_sort_inner(start, q) | circle_sort_inner(p, end);
}

//helper function to show arrays before each call
void circle_sort(int *x, int n)
{
	do {
		int i;
		for (i = 0; i < n; i++) printf("%d ", x[i]);
		putchar('\n');
	} while (circle_sort_inner(x, x + (n - 1)));
}

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
	int x[] = {5, -1, 101, -4, 0, 1, 8, 6, 2, 3};
	circle_sort(x, sizeof(x) / sizeof(*x));

	return 0;
}