#include <stdio.h>

void t(int n)
{
	int i, j, c, len;

	i = n * (n - 1) / 2;
	for (len = c = 1; c < i; c *= 10, len++);
	c -= i; // c is the col where width changes

#define SPEED_MATTERS 0
#if SPEED_MATTERS	// in case we really, really wanted to print huge triangles often
	char tmp[32], s[4096], *p;

	sprintf(tmp, "%*d", len, 0);

	inline void inc_numstr(void) {
		int k = len;

	redo:	if (!k--) return;

		if (tmp[k] == '9') {
			tmp[k] = '0';
			goto redo;
		}

		if (++tmp[k] == '!')
			tmp[k] = '1';
	}

	for (p = s, i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			inc_numstr();
			__builtin_memcpy(p, tmp + 1 - (j >= c), len - (j < c));
			p += len - (j < c);

			*(p++) = (i - j)? ' ' : '\n';

			if (p - s + len >= 4096) {
				fwrite(s, 1, p - s, stdout);
				p = s;
			}
		}
	}

	fwrite(s, 1, p - s, stdout);
#else // NO_IT_DOESN'T
	int num;
	for (num = i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
			printf("%*d%c",	len - (j < c), num++, i - j ? ' ':'\n');
#endif
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
	t(5), t(14);

	// maybe not 
	// t(10000);
	return 0;
}