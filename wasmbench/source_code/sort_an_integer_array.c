#include <stdlib.h>  /* qsort() */
#include <stdio.h>   /* printf() */

int intcmp(const void *aa, const void *bb)
{
    const int *a = aa, *b = bb;
    return (*a < *b) ? -1 : (*a > *b);
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
    int nums[5] = {2,4,3,1,2};
    qsort(nums, 5, sizeof(int), intcmp);
    printf("result: %d %d %d %d %d\n",
      nums[0], nums[1], nums[2], nums[3], nums[4]);
    return 0;
}