#include <stdio.h>
#include <string.h>

const char *A[] = { "John", "Serena", "Bob", "Mary", "Serena" };
const char *B[] = { "Jim", "Mary", "John", "Jim", "Bob" };

#define LEN(x) sizeof(x)/sizeof(x[0])

/* null duplicate items */
void uniq(const char *x[], int len)
{
	int i, j;
	for (i = 0; i < len; i++)
		for (j = i + 1; j < len; j++)
			if (x[j] && x[i] && !strcmp(x[i], x[j])) x[j] = 0;
}

int in_set(const char *const x[], int len, const char *match)
{
	int i;
	for (i = 0; i < len; i++)
		if (x[i] && !strcmp(x[i], match))
			return 1;
	return 0;
}

/* x - y */
void show_diff(const char *const x[], int lenx, const char *const y[], int leny)
{
	int i;
	for (i = 0; i < lenx; i++)
		if (x[i] && !in_set(y, leny, x[i]))
			printf("  %s\n", x[i]);
}

/* X ^ Y */
void show_sym_diff(const char *const x[], int lenx, const char *const y[], int leny)
{
	show_diff(x, lenx, y, leny);
	show_diff(y, leny, x, lenx);
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
	uniq(A, LEN(A));
	uniq(B, LEN(B));
	printf("A \\ B:\n"); show_diff(A, LEN(A), B, LEN(B));
	printf("\nB \\ A:\n"); show_diff(B, LEN(B), A, LEN(A));
	printf("\nA ^ B:\n");  show_sym_diff(A, LEN(A), B, LEN(B));

	return 0;
}