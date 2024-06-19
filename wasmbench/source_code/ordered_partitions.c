#include <stdio.h>

typedef unsigned int uint;

int parts[] = {2, 1, 2};
#define n_parts sizeof(parts)/sizeof(parts[0])
int bits[n_parts];

void show_part(uint x)
{
	uint i;
	putchar('{');
	for (i = 0; (1 << i) <= x; i ++)
		if (x & (1 << i)) printf(" %d", i + 1);

	printf("%s", " } ");
}

void gen_bits(uint mask, uint all, uint res, int n, int pid)
{
	uint i;
	while (!n) {
		bits[pid++] = res;
		if (pid == n_parts) {
			for (i = 0; i < n_parts; i++)
				show_part(bits[i]);
			putchar('\n');
			return;
		}
		mask = all &= ~res;
		res = 0;
		n = parts[pid];
	}

	while (mask) {
		mask &= ~(i = mask & -(int)mask);
		gen_bits(mask, all, res | i, n - 1, pid);
	}
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
	uint i, m;
	for (m = 1, i = 0; i < n_parts; i++)
		m <<= parts[i];
	m--;

	gen_bits(m, m, 0, parts[0], 0);

	return 0;
}