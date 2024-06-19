#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*cmp_func)(const void*, const void*);

void perm_sort(void *a, int n, size_t msize, cmp_func _cmp)
{
	char *p, *q, *tmp = malloc(msize);
#	define A(i) ((char *)a + msize * (i))
#	define swap(a, b) {\
		memcpy(tmp, a, msize);\
		memcpy(a, b, msize);\
		memcpy(b, tmp, msize);	}
	while (1) {
		/* find largest k such that a[k - 1] < a[k] */
		for (p = A(n - 1); (void*)p > a; p = q)
			if (_cmp(q = p - msize, p) > 0)
				break;

		if ((void*)p <= a) break;

		/* find largest l such that a[l] > a[k - 1] */
		for (p = A(n - 1); p > q; p-= msize)
			if (_cmp(q, p) > 0) break;

		swap(p, q); /* swap a[k - 1], a[l] */
		/* flip a[k] through a[end] */
		for (q += msize, p = A(n - 1); q < p; q += msize, p -= msize)
			swap(p, q);
	}
	free(tmp);
}

int scmp(const void *a, const void *b) { return strcmp(*(const char *const *)a, *(const char *const *)b); }

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
	int i;
	const char *strs[] = { "spqr", "abc", "giant squid", "stuff", "def" };
	perm_sort(strs, 5, sizeof(*strs), scmp);

	for (i = 0; i < 5; i++)
		printf("%s\n", strs[i]);
	return 0;
}