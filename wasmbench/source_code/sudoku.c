#include <stdio.h>

void show(int *x)
{
	int i, j;
	for (i = 0; i < 9; i++) {
		if (!(i % 3)) putchar('\n');
		for (j = 0; j < 9; j++)
			printf(j % 3 ? "%2d" : "%3d", *x++);
		putchar('\n');
	}
}

int trycell(int *x, int pos)
{
	int row = pos / 9;
	int col = pos % 9;
	int i, j, used = 0;

	if (pos == 81) return 1;
	if (x[pos]) return trycell(x, pos + 1);

	for (i = 0; i < 9; i++)
		used |= 1 << (x[i * 9 + col] - 1);

	for (j = 0; j < 9; j++)
		used |= 1 << (x[row * 9 + j] - 1);

	row = row / 3 * 3;
	col = col / 3 * 3;
	for (i = row; i < row + 3; i++)
		for (j = col; j < col + 3; j++)
			used |= 1 << (x[i * 9 + j] - 1);

	for (x[pos] = 1; x[pos] <= 9; x[pos]++, used >>= 1)
		if (!(used & 1) && trycell(x, pos + 1)) return 1;

	x[pos] = 0;
	return 0;
}

void solve(const char *s)
{
	int i, x[81];
	for (i = 0; i < 81; i++)
		x[i] = s[i] >= '1' && s[i] <= '9' ? s[i] - '0' : 0;

	if (trycell(x, 0))
		show(x);
	else
		puts("no solution");
}

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
	solve(	"5x..7...."
		"6..195..."
		".98....6."
		"8...6...3"
		"4..8.3..1"
		"7...2...6"
		".6....28."
		"...419..5"
		"....8..79"	);

	return 0;
}