#include <stdio.h>

// can be any swap function. This swap is optimized for numbers.
void swap(int *x, int *y) {
	if(x == y)
		return;
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
void cocktailsort(int *a, size_t n) {
	while(1) {
		// packing two similar loops into one
		char flag;
		size_t start[2] = {1, n - 1},
			   end[2] = {n, 0},
			   inc[2] = {1, -1};
		for(int it = 0; it < 2; ++it) {
			flag = 1;
			for(int i = start[it]; i != end[it]; i += inc[it])
				if(a[i - 1] > a[i]) {
					swap(a + i - 1, a + i);
					flag = 0;
				}
			if(flag)
				return;
		}
	}
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(void) {
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
	int a[] = { 5, -1, 101, -4, 0, 1, 8, 6, 2, 3 };
	size_t n = sizeof(a)/sizeof(a[0]);

	cocktailsort(a, n);
	for (size_t i = 0; i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}