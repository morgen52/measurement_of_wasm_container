#include <stdio.h>

void vc(int n, int base, int *num, int *denom)
{
        int p = 0, q = 1;

        while (n) {
                p = p * base + (n % base);
                q *= base;
                n /= base;
        }

        *num = p;  
        *denom = q;

        while (p) { n = p; p = q % p; q = n; }
        *num /= q;
        *denom /= q;
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
        int d, n, i, b;
        for (b = 2; b < 6; b++) {
                printf("base %d:", b);
                for (i = 0; i < 10; i++) {
                        vc(i, b, &n, &d);
                        if (n) printf("  %d/%d", n, d);
                        else   printf("  0");
                }
                printf("\n");
        }

        return 0;
}