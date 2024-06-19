#include <stdio.h>

#define WIDTH 81
#define HEIGHT 5

char lines[HEIGHT][WIDTH];

void init() {
    int i, j;
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) lines[i][j] = '*';
    }
}

void cantor(int start, int len, int index) {
    int i, j, seg = len / 3;
    if (seg == 0) return;
    for (i = index; i < HEIGHT; ++i) {
        for (j = start + seg; j < start + seg * 2; ++j) lines[i][j] = ' ';
    }
    cantor(start, seg, index + 1);
    cantor(start + seg * 2, seg, index + 1);
}

void print() {
    int i, j;
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) printf("%c", lines[i][j]);
        printf("\n");
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
    init();
    cantor(0, WIDTH, 1);
    print();
    return 0;
}