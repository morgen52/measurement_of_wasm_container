#include <stdio.h>
#include <stdlib.h>

void bead_sort(int *a, int len)
{
	int i, j, max, sum;
	unsigned char *beads;
#	define BEAD(i, j) beads[i * max + j]

	for (i = 1, max = a[0]; i < len; i++)
		if (a[i] > max) max = a[i];

	beads = calloc(1, max * len);

	/* mark the beads */
	for (i = 0; i < len; i++)
		for (j = 0; j < a[i]; j++)
			BEAD(i, j) = 1;

	for (j = 0; j < max; j++) {
		/* count how many beads are on each post */
		for (sum = i = 0; i < len; i++) {
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		/* mark bottom sum beads */
		for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < max && BEAD(i, j); j++);
		a[i] = j;
	}
	free(beads);
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
	int i, x[] = {5, 3, 1, 7, 4, 1, 1, 20};
	int len = sizeof(x)/sizeof(x[0]);

	bead_sort(x, len);
	for (i = 0; i < len; i++)
		printf("%d\n", x[i]);

	return 0;
}