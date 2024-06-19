#include <stdio.h>
#include <stdlib.h>

typedef struct stem_t *stem;
struct stem_t { const char *str; stem next; };

void tree(int root, stem head)
{
	static const char *sdown = "  |", *slast = "  `", *snone = "   ";
	struct stem_t col = {0, 0}, *tail;

	for (tail = head; tail; tail = tail->next) {
		printf("%s", tail->str);
		if (!tail->next) break;
	}

	printf("--%d\n", root);

	if (root <= 1) return;

	if (tail && tail->str == slast)
		tail->str = snone;

	if (!tail)	tail = head = &col;
	else		tail->next = &col;

	while (root) { // make a tree by doing something random
		int r = 1 + (rand() % root);
		root -= r;
		col.str = root ? sdown : slast;

		tree(r, head);
	}

	tail->next = 0;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int c, char**v)
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
	int n;
	if (c < 2 || (n = atoi(v[1])) < 0) n = 8;

	tree(n, 0);
	return 0;
}