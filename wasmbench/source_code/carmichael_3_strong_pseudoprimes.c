
#include <stdio.h>

/* C's % operator actually calculates the remainder of a / b so we need a
 * small adjustment so it works as expected for negative values */
#define mod(n,m) ((((n) % (m)) + (m)) % (m))

int is_prime(unsigned int n)
{
    if (n <= 3) {
        return n > 1;
    }
    else if (!(n % 2) || !(n % 3)) {
        return 0;
    }
    else {
        unsigned int i;
        for (i = 5; i*i <= n; i += 6)
            if (!(n % i) || !(n % (i + 2)))
                return 0;
        return 1;
    }
}

void carmichael3(int p1)
{
    if (!is_prime(p1)) return;

    int h3, d, p2, p3;
    for (h3 = 1; h3 < p1; ++h3) {
        for (d = 1; d < h3 + p1; ++d) {
            if ((h3 + p1)*(p1 - 1) % d == 0 && mod(-p1 * p1, h3) == d % h3) {
                p2 = 1 + ((p1 - 1) * (h3 + p1)/d);
                if (!is_prime(p2)) continue;
                p3 = 1 + (p1 * p2 / h3);
                if (!is_prime(p3) || (p2 * p3) % (p1 - 1) != 1) continue;
                printf("%d %d %d\n", p1, p2, p3);
            }
        }
    }
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
    int p1;
    for (p1 = 2; p1 < 62; ++p1)
        carmichael3(p1);
    return 0;
}
