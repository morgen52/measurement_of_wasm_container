#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) do{t=(a);(a)=(b);(b)=t;}while(0)

void _mr_unrank1(int rank, int n, int *vec) {
    int t, q, r;
    if (n < 1) return;

    q = rank / n;
    r = rank % n;
    SWAP(vec[r], vec[n-1]);
    _mr_unrank1(q, n-1, vec);
}

int _mr_rank1(int n, int *vec, int *inv) {
    int s, t;
    if (n < 2) return 0;

    s = vec[n-1];
    SWAP(vec[n-1], vec[inv[n-1]]);
    SWAP(inv[s], inv[n-1]);
    return s + n * _mr_rank1(n-1, vec, inv);
}

/* Fill the integer array <vec> (of size <n>) with the
 * permutation at rank <rank>.
 */
void get_permutation(int rank, int n, int *vec) {
    int i;
    for (i = 0; i < n; ++i) vec[i] = i;
    _mr_unrank1(rank, n, vec);
}

/* Return the rank of the current permutation of array <vec>
 * (of size <n>).
 */
int get_rank(int n, int *vec) {
    int i, r, *v, *inv;

    v = malloc(n * sizeof(int));
    inv = malloc(n * sizeof(int));

    for (i = 0; i < n; ++i) {
        v[i] = vec[i];
        inv[vec[i]] = i;
    }
    r = _mr_rank1(n, v, inv);
    free(inv);
    free(v);
    return r;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char *argv[]) {
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
    int i, r, tv[4];

    for (r = 0; r < 24; ++r) {
        printf("%3d: ", r);
        get_permutation(r, 4, tv);

        for (i = 0; i < 4; ++i) {
            if (0 == i) printf("[ ");
            else printf(", ");
            printf("%d", tv[i]);
        }
        printf(" ] = %d\n", get_rank(4, tv));
    }
}
