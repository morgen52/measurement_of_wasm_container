#include <stdio.h>

typedef unsigned uint;
int is_prime(uint n)
{
        if (!(n%2) || !(n%3)) return 0;
        uint p = 1;
        while(p*p < n)
                if (n%(p += 4) == 0 || n%(p += 2) == 0)
                        return 0;
        return 1;
}

uint reverse(uint n)
{
        uint r;
        for (r = 0; n; n /= 10)
                r = r*10 + (n%10);
        return r;
}

int is_emirp(uint n)
{
        uint r = reverse(n);
        return r != n && is_prime(n) && is_prime(r);
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char **argv)
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
        uint x, c = 0;
        switch(argc) { // advanced args parsing
        case 1: for (x = 11; c < 20; x += 2)
                        if (is_emirp(x))
                                printf(" %u", x), ++c;
                break;

        case 2: for (x = 7701; x < 8000; x += 2)
                        if (is_emirp(x))
                                printf(" %u", x);
                break;

        default:
                for (x = 11; ; x += 2)
                        if (is_emirp(x) && ++c == 10000) {
                                printf("%u", x);
                                break;
                        }
        }

        putchar('\n');
        return 0;
}