#include <stdio.h>
#include <stdlib.h>

// row starts with 1; col < row
size_t bellIndex(int row, int col) {
    return row * (row - 1) / 2 + col;
}

int getBell(int *bellTri, int row, int col) {
    size_t index = bellIndex(row, col);
    return bellTri[index];
}

void setBell(int *bellTri, int row, int col, int value) {
    size_t index = bellIndex(row, col);
    bellTri[index] = value;
}

int *bellTriangle(int n) {
    size_t length = n * (n + 1) / 2;
    int *tri = calloc(length, sizeof(int));
    int i, j;

    setBell(tri, 1, 0, 1);
    for (i = 2; i <= n; ++i) {
        setBell(tri, i, 0, getBell(tri, i - 1, i - 2));
        for (j = 1; j < i; ++j) {
            int value = getBell(tri, i, j - 1) + getBell(tri, i - 1, j - 1);
            setBell(tri, i, j, value);
        }
    }

    return tri;
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
    const int rows = 15;
    int *bt = bellTriangle(rows);
    int i, j;

    printf("First fifteen Bell numbers:\n");
    for (i = 1; i <= rows; ++i) {
        printf("%2d: %d\n", i, getBell(bt, i, 0));
    }

    printf("\nThe first ten rows of Bell's triangle:\n");
    for (i = 1; i <= 10; ++i) {
        printf("%d", getBell(bt, i, 0));
        for (j = 1; j < i; ++j) {
            printf(", %d", getBell(bt, i, j));
        }
        printf("\n");
    }

    free(bt);
    return 0;
}