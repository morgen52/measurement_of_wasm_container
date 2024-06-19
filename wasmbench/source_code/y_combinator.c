#include <stdio.h>
#include <stdlib.h>

/* func: our one and only data type; it holds either a pointer to
   a function call, or an integer.  Also carry a func pointer to
   a potential parameter, to simulate closure                   */
typedef struct func_t *func;
typedef struct func_t {
        func (*fn) (func, func);
        func _;
        int num;
} func_t;

func new(func(*f)(func, func), func _) {
        func x = malloc(sizeof(func_t));
        x->fn = f;
        x->_ = _;       /* closure, sort of */
        x->num = 0;
        return x;
}

func call(func f, func n) {
        return f->fn(f, n);
}

func Y(func(*f)(func, func)) {
        func g = new(f, 0);
        g->_ = g;
        return g;
}

func num(int n) {
        func x = new(0, 0);
        x->num = n;
        return x;
}


func fac(func self, func n) {
        int nn = n->num;
        return nn > 1   ? num(nn * call(self->_, num(nn - 1))->num)
                        : num(1);
}

func fib(func self, func n) {
        int nn = n->num;
        return nn > 1
                ? num(  call(self->_, num(nn - 1))->num +
                        call(self->_, num(nn - 2))->num )
                : num(1);
}

void show(func n) { printf(" %d", n->num); }

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
        int i;
        func f = Y(fac);
        printf("fac: ");
        for (i = 1; i < 10; i++)
                show( call(f, num(i)) );
        printf("\n");

        f = Y(fib);
        printf("fib: ");
        for (i = 1; i < 10; i++)
                show( call(f, num(i)) );
        printf("\n");

        return 0;
}
