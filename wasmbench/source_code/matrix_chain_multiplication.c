#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int **m;
int **s;

void optimal_matrix_chain_order(int *dims, int n) {
    int len, i, j, k, temp, cost;
    n--;
    m = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; ++i) {
        m[i] = (int *)calloc(n, sizeof(int));
    }

    s = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; ++i) {
        s[i] = (int *)calloc(n, sizeof(int));
    }

    for (len = 1; len < n; ++len) {
        for (i = 0; i < n - len; ++i) {
            j = i + len;
            m[i][j] = INT_MAX;
            for (k = i; k < j; ++k) {
                temp = dims[i] * dims[k + 1] * dims[j + 1];
                cost = m[i][k] + m[k + 1][j] + temp;
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_chain_order(int i, int j) {
    if (i == j)
        printf("%c", i + 65);
    else {
        printf("(");
        print_optimal_chain_order(i, s[i][j]);
        print_optimal_chain_order(s[i][j] + 1, j);
        printf(")");
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
    int i, j, n;
    int a1[4]  = {5, 6, 3, 1};
    int a2[13] = {1, 5, 25, 30, 100, 70, 2, 1, 100, 250, 1, 1000, 2};
    int a3[12] = {1000, 1, 500, 12, 1, 700, 2500, 3, 2, 5, 14, 10};
    int *dims_list[3] = {a1, a2, a3};
    int sizes[3] = {4, 13, 12};
    for (i = 0; i < 3; ++i) {
        printf("Dims  : [");
        n = sizes[i];
        for (j = 0; j < n; ++j) {
            printf("%d", dims_list[i][j]);
            if (j < n - 1) printf(", "); else printf("]\n");
        }        
        optimal_matrix_chain_order(dims_list[i], n);
        printf("Order : ");
        print_optimal_chain_order(0, n - 2);
        printf("\nCost  : %d\n\n", m[0][n - 2]);
        for (j = 0; j <= n - 2; ++j) free(m[j]);
        free(m);
        for (j = 0; j <= n - 2; ++j) free(s[j]);
        free(s);
    }
    return 0;
}