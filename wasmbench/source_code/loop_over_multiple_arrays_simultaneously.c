#include <stdio.h>

char a1[] = {'a','b','c'};
char a2[] = {'A','B','C'};
int a3[] = {1,2,3};

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(void) {
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
    for (int i = 0; i < 3; i++) {
        printf("%c%c%i\n", a1[i], a2[i], a3[i]);
    }
}