
#include <stdio.h>

#define twidth 5
#define mdr(rmdr, rmp, n)\
    do { *rmp = 0; _mdr(rmdr, rmp, n); } while (0)

void _mdr(int *rmdr, int *rmp, long long n)
{
    /* Adjust r if 0 case, so we don't return 1 */
    int r = n ? 1 : 0;
    while (n) { 
        r *= (n % 10);
        n /= 10; 
    }

    (*rmp)++;
    if (r >= 10)
        _mdr(rmdr, rmp, r);
    else
        *rmdr = r;
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
    int i, j, vmdr, vmp;
    const int values[] = { 123321, 7739, 893, 899998 };
    const int vsize    = sizeof(values) / sizeof(values[0]);

    /* Initial test values */
    printf("Number    MDR    MP\n");
    for (i = 0; i < vsize; ++i) {
        mdr(&vmdr, &vmp, values[i]);
        printf("%6d   %3d   %3d\n", values[i], vmdr, vmp);
    }

    /* Determine table values */
    int table[10][twidth] = { 0 };
    int tfill[10]         = { 0 };
    int total             = 0;
    for (i = 0; total < 10 * twidth; ++i) {
        mdr(&vmdr, &vmp, i);
        if (tfill[vmdr] < twidth) {
            table[vmdr][tfill[vmdr]++] = i;
            total++;
        }
    }

    /* Print calculated table values */
    printf("\nMDR: [n0..n4]\n");
    for (i = 0; i < 10; ++i) {
        printf("%3d: [", i);
        for (j = 0; j < twidth; ++j)
            printf("%d%s", table[i][j], j != twidth - 1 ? ", " : ""); 
        printf("]\n");
    }

    return 0;
}
