#include <stdio.h>
#include <math.h>

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
    for (int i = 1; i < 5000; i++) {
        // loop through each digit in i
        // e.g. for 1000 we get 0, 0, 0, 1.
        int sum = 0;
        for (int number = i; number > 0; number /= 10) {
            int digit = number % 10;
            // find the sum of the digits 
            // raised to themselves 
            sum += pow(digit, digit);
        }
        if (sum == i) {
            // the sum is equal to the number
            // itself; thus it is a 
            // munchausen number
            printf("%i\n", i);
        } 
    }
    return 0;
}