
#include <stdio.h>
#include <math.h>

#define max(x,y)  ((x) > (y) ? (x) : (y))

int tri[] = {
        55,
	94, 48,
	95, 30, 96,
	77, 71, 26, 67,
	97, 13, 76, 38, 45,
	7, 36, 79, 16, 37, 68,
	48, 7, 9, 18, 70, 26, 6,
	18, 72, 79, 46, 59, 79, 29, 90,
	20, 76, 87, 11, 32, 7, 7, 49, 18,
	27, 83, 58, 35, 71, 11, 25, 57, 29, 85,
	14, 64, 36, 96, 27, 11, 58, 56, 92, 18, 55,
	2, 90, 3, 60, 48, 49, 41, 46, 33, 36, 47, 23,
	92, 50, 48, 2, 36, 59, 42, 79, 72, 20, 82, 77, 42,
	56, 78, 38, 80, 39, 75, 2, 71, 66, 66, 1, 3, 55, 72,
	44, 25, 67, 84, 71, 67, 11, 61, 40, 57, 58, 89, 40, 56, 36,
	85, 32, 25, 85, 57, 48, 84, 35, 47, 62, 17, 1, 1, 99, 89, 52,
	6, 71, 28, 75, 94, 48, 37, 10, 23, 51, 6, 48, 53, 18, 74, 98, 15,
	27, 2, 92, 23, 8, 71, 76, 84, 15, 52, 92, 63, 81, 10, 44, 10, 69, 93
};

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
    const int len  = sizeof(tri) / sizeof(tri[0]);
    const int base = (sqrt(8*len + 1) - 1) / 2;
    int step       = base - 1;
    int stepc      = 0;

    int i;
    for (i = len - base - 1; i >= 0; --i) {
        tri[i] += max(tri[i + step], tri[i + step + 1]);
        if (++stepc == step) {
            step--;
            stepc = 0;
        }
    }

    printf("%d\n", tri[0]);
    return 0;
}
