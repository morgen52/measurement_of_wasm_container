#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX 120

typedef int bool;

bool is_prime(int n) {
    int d = 5;
    if (n < 2) return FALSE;
    if (!(n % 2)) return n == 2;
    if (!(n % 3)) return n == 3;
    while (d *d <= n) {
        if (!(n % d)) return FALSE;
        d += 2;
        if (!(n % d)) return FALSE;
        d += 4;
    }
    return TRUE;
}

int count_prime_factors(int n) {
    int count = 0, f = 2;
    if (n == 1) return 0;
    if (is_prime(n)) return 1;
    while (TRUE) {
        if (!(n % f)) {
            count++;
            n /= f;
            if (n == 1) return count;
            if (is_prime(n)) f = n;
        } 
        else if (f >= 3) f += 2;
        else f = 3;
    }
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main() {    
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
    int i, n, count = 0;
    printf("The attractive numbers up to and including %d are:\n", MAX);
    for (i = 1; i <= MAX; ++i) {
        n = count_prime_factors(i);
        if (is_prime(n)) {
            printf("%4d", i);
            if (!(++count % 20)) printf("\n");
        }
    }
    printf("\n");
    return 0;  
}