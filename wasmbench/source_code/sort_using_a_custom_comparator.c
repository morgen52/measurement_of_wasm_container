#include <stdlib.h>  /* for qsort */
#include <string.h>  /* for strlen */
#include <strings.h> /* for strcasecmp */

int mycmp(const void *s1, const void *s2)
{
    const char *l = *(const char **)s1, *r = *(const char **)s2;
    size_t ll = strlen(l), lr = strlen(r);

    if (ll > lr) return -1;
    if (ll < lr) return 1;
    return strcasecmp(l, r);
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
    const char *strings[] = {
      "Here", "are", "some", "sample", "strings", "to", "be", "sorted" };

    qsort(strings, sizeof(strings)/sizeof(*strings), sizeof(*strings), mycmp);
    return 0;
}