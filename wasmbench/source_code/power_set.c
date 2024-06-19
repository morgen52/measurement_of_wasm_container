#include <stdio.h>

struct node {
	char *s;
	struct node* prev;
};

void powerset(char **v, int n, struct node *up)
{
	struct node me;

	if (!n) {
		putchar('[');
		while (up) {
			printf(" %s", up->s);
			up = up->prev;
		}
		puts(" ]");
	} else {
		me.s = *v;
		me.prev = up;
		powerset(v + 1, n - 1, up);
		powerset(v + 1, n - 1, &me);
	}
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
	powerset(argv + 1, argc - 1, 0);
	return 0;
}