#include <stdio.h>
#include <string.h>

int qselect(int *v, int len, int k)
{
#	define SWAP(a, b) { tmp = v[a]; v[a] = v[b]; v[b] = tmp; }
	int i, st, tmp;

	for (st = i = 0; i < len - 1; i++) {
		if (v[i] > v[len-1]) continue;
		SWAP(i, st);
		st++;
	}

	SWAP(len-1, st);

	return k == st	?v[st]
			:st > k	? qselect(v, st, k)
				: qselect(v + st, len - st, k - st);
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
#	define N (sizeof(x)/sizeof(x[0]))
	int x[] = {9, 8, 7, 6, 5, 0, 1, 2, 3, 4};
	int y[N];

	int i;
	for (i = 0; i < 10; i++) {
		memcpy(y, x, sizeof(x)); // qselect modifies array
		printf("%d: %d\n", i, qselect(y, 10, i));
	}

	return 0;
}