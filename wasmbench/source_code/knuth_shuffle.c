#include <stdio.h>
#include <stdlib.h>
 
/* define a shuffle function. e.g. decl_shuffle(double).
 * advantage: compiler is free to optimize the swap operation without
 *            indirection with pointers, which could be much faster.
 * disadvantage: each datatype needs a separate instance of the function.
 *            for a small funciton like this, it's not very big a deal.
 */
#define decl_shuffle(type)				\
void shuffle_##type(type *list, size_t len) {		\
	int j;						\
	type tmp;					\
	while(len) {					\
		j = irand(len);				\
		if (j != len - 1) {			\
			tmp = list[j];			\
			list[j] = list[len - 1];	\
			list[len - 1] = tmp;		\
		}					\
		len--;					\
	}						\
}							\

/* random integer from 0 to n-1 */
int irand(int n)
{
	int r, rand_max = RAND_MAX - (RAND_MAX % n);
	/* reroll until r falls in a range that can be evenly
	 * distributed in n bins.  Unless n is comparable to
	 * to RAND_MAX, it's not *that* important really. */
	while ((r = rand()) >= rand_max);
	return r / (rand_max / n);
}
 
/* declare and define int type shuffle function from macro */
decl_shuffle(int);
 
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
	int i, x[20];
 
	for (i = 0; i < 20; i++) x[i] = i;
	for (printf("before:"), i = 0; i < 20 || !printf("\n"); i++)
		printf(" %d", x[i]);
 
	shuffle_int(x, 20);
 
	for (printf("after: "), i = 0; i < 20 || !printf("\n"); i++)
		printf(" %d", x[i]);
	return 0;
}