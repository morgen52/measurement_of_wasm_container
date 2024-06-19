#include <stdio.h>
#include <stdlib.h>

struct item { double w, v; const char *name; } items[] = {
	{ 3.8, 36, "beef" },
	{ 5.4, 43, "pork" },
	{ 3.6, 90, "ham" },
	{ 2.4, 45, "greaves" },
	{ 4.0, 30, "flitch" },
	{ 2.5, 56, "brawn" },
	{ 3.7, 67, "welt" },
	{ 3.0, 95, "salami" },
	{ 5.9, 98, "sausage" },
};

int item_cmp(const void *aa, const void *bb)
{
	const struct item *a = aa, *b = bb;
	double ua = a->v / a->w, ub = b->v / b->w;
	return ua < ub ? -1 : ua > ub;
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
	struct item *it;
	double space = 15;

	qsort(items, 9, sizeof(struct item), item_cmp);
	for (it = items + 9; it---items && space > 0; space -= it->w)
		if (space >= it->w)
			printf("take all %s\n", it->name);
		else
			printf("take %gkg of %g kg of %s\n",
				space, it->w, it->name);

	return 0;
}