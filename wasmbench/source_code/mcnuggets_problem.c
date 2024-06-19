#include <stdio.h>

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
    int max = 0, i = 0, sixes, nines, twenties;

loopstart: while (i < 100) {
        for (sixes = 0; sixes*6 < i; sixes++) {
            if (sixes*6 == i) {
                i++;
                goto loopstart;
            }

            for (nines = 0; nines*9 < i; nines++) {
                if (sixes*6 + nines*9 == i) {
                    i++;
                    goto loopstart;
                }

                for (twenties = 0; twenties*20 < i; twenties++) {
                    if (sixes*6 + nines*9 + twenties*20 == i) {
                        i++;
                        goto loopstart;
                    }
                }
            }
        }
        max = i;
        i++;
    }

    printf("Maximum non-McNuggets number is %d\n", max);

    return 0;
}