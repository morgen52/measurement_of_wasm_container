#include <stdio.h>
#include <stdlib.h>

int list[] = {-7, 1, 5, 2, -4, 3, 0};

int eq_idx(int *a, int len, int **ret)
{
	int i, sum, s, cnt;
	/* alloc long enough: if we can afford the original list,
	 * we should be able to afford to this.  Beats a potential
         * million realloc() calls.  Even if memory is a real concern,
         * there's no garantee the result is shorter than the input anyway */
        cnt = s = sum = 0;
	*ret = malloc(sizeof(int) * len);

	for (i = 0; i < len; i++)
                sum += a[i];

	for (i = 0; i < len; i++) {
		if (s * 2 + a[i] == sum) {
			(*ret)[cnt] = i;
                        cnt++;
                }
		s += a[i];
	}

        /* uncouraged way to use realloc since it can leak memory, for example */
	*ret = realloc(*ret, cnt * sizeof(int));

	return cnt;
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
	int i, cnt, *idx;
	cnt = eq_idx(list, sizeof(list) / sizeof(int), &idx);

	printf("Found:");
	for (i = 0; i < cnt; i++)
                printf(" %d", idx[i]);
	printf("\n");

	return 0;
}