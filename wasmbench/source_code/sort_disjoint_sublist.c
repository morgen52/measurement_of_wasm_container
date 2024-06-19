#include <stdio.h>

/* yes, bubble sort */
void bubble_sort(int *idx, int n_idx, int *buf)
{
        int i, j, tmp;
#define for_ij for (i = 0; i < n_idx; i++) for (j = i + 1; j < n_idx; j++)
#define sort(a, b) if (a < b) { tmp = a; a = b; b = tmp;}
        for_ij { sort(idx[j], idx[i]);          }
        for_ij { sort(buf[idx[j]], buf[idx[i]]);}
#undef for_ij
#undef sort
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
        int values[] = {7, 6, 5, 4, 3, 2, 1, 0};
        int idx[] = {6, 1, 7};
        int i;

        printf("before sort:\n");
        for (i = 0; i < 8; i++)
                printf("%d ", values[i]);

        printf("\n\nafter sort:\n");
        bubble_sort(idx, 3, values);

        for (i = 0; i < 8; i++)
                printf("%d ", values[i]);
        printf("\n");

        return 0;
}