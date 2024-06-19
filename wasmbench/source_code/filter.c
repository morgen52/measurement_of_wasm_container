#include <stdio.h>
#include <stdlib.h>

int even_sel(int x) { return !(x & 1); }
int tri_sel(int x) { return x % 3; }

/* using a predicate function sel() to select elements */
int* grep(int *in, int len, int *outlen, int (*sel)(int), int inplace)
{
	int i, j, *out;

	if (inplace)	out = in;
	else		out = malloc(sizeof(int) * len);

	for (i = j = 0; i < len; i++)
		if (sel(in[i]))
			out[j++] = in[i];

	if (!inplace && j < len)
		out = realloc(out, sizeof(int) * j);

	*outlen = j;
	return out;
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
	int in[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i, len;

	int *even = grep(in, 10, &len, even_sel, 0);
	printf("Filtered even:");
	for (i = 0; i < len; i++) printf(" %d", even[i]);
	printf("\n");

	grep(in, 8, &len, tri_sel, 1);
	printf("In-place filtered not multiple of 3:");
	for (i = 0; i < len; i++) printf(" %d", in[i]);

	printf("\n");

	return 0;
}