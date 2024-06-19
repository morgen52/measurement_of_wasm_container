/* man-or-boy.c */
#include <stdio.h>
#include <stdlib.h>

// --- thunks
typedef struct arg
{
  int       (*fn)(struct arg*);
  int        *k;
  struct arg *x1, *x2, *x3, *x4, *x5;
} ARG;

// --- lambdas
int f_1 (ARG* _) { return -1; }
int f0  (ARG* _) { return  0; }
int f1  (ARG* _) { return  1; }

// --- helper
int eval(ARG* a) { return a->fn(a); }
#define MAKE_ARG(...) (&(ARG){__VA_ARGS__})
#define FUN(...) MAKE_ARG(B, &k, __VA_ARGS__)

int A(ARG*);

// --- functions
int B(ARG* a)
{
  int k = *a->k -= 1;
  return A(FUN(a, a->x1, a->x2, a->x3, a->x4));
}

int A(ARG* a)
{
  return *a->k <= 0 ? eval(a->x4) + eval(a->x5) : B(a);
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char **argv)
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
  int k = argc == 2 ? strtol(argv[1], 0, 0) : 10;
  printf("%d\n", A(FUN(MAKE_ARG(f1), MAKE_ARG(f_1), MAKE_ARG(f_1),
                       MAKE_ARG(f1), MAKE_ARG(f0))));
  return 0;
}