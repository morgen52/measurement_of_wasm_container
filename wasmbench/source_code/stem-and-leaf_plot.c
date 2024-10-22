#include <stdio.h>
#include <stdlib.h>

int icmp(const void *a, const void *b)
{
	return *(const int*)a < *(const int*)b ? -1 : *(const int*)a > *(const int*)b;
}

void leaf_plot(int *x, int len)
{
	int i, j, d;

	qsort(x, len, sizeof(int), icmp);

	i = x[0] / 10 - 1;
	for (j = 0; j < len; j++) {
		d = x[j] / 10;
		while (d > i) printf("%s%3d |", j ? "\n" : "", ++i);
		printf(" %d", x[j] % 10);
	}
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
	int data[] = {
	  12, 127,  28,  42,  39, 113,  42,  18,  44, 118,  44,  37, 113, 124,
	  37,  48, 127,  36,  29,  31, 125, 139, 131, 115, 105, 132, 104, 123,
	  35, 113, 122,  42, 117, 119,  58, 109,  23, 105,  63,  27,  44, 105,
	  99,  41, 128, 121, 116, 125,  32,  61,  37, 127,  29, 113, 121,  58,
	 114, 126,  53, 114,  96,  25, 109,   7,  31, 141,  46,  13,  27,  43,
	 117, 116,  27,   7,  68,  40,  31, 115, 124,  42, 128,  52,  71, 118,
	 117,  38,  27, 106,  33, 117, 116, 111,  40, 119,  47, 105,  57, 122,
	 109, 124, 115,  43, 120,  43,  27,  27,  18,  28,  48, 125, 107, 114,
	  34, 133,  45, 120,  30, 127,  31, 116, 146 };

	leaf_plot(data, sizeof(data)/sizeof(data[0]));

	return 0;
}