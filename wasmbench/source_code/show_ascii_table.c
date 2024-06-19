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
    int i, j;
    char k[4];
    for (i = 0; i < 16; ++i) {
        for (j = 32 + i; j < 128; j += 16) {
            switch (j) {
                default:  sprintf(k, "%c", j); break;
                case 32:  sprintf(k, "Spc"); break;
                case 127: sprintf(k, "Del"); break;
            }
            printf("%3d : %-3s   ", j, k);
        }
        printf("\n");
    }
    return 0;
}