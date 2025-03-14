#include <stdio.h>
#include <stdint.h>

void to_seq(uint64_t x, uint8_t *out)
{
	int i, j;
	for (i = 9; i > 0; i--) {
		if (x & 127ULL << i * 7) break;
	}
	for (j = 0; j <= i; j++)
		out[j] = ((x >> ((i - j) * 7)) & 127) | 128;

	out[i] ^= 128;
}

uint64_t from_seq(uint8_t *in)
{
	uint64_t r = 0;

	do {
		r = (r << 7) | (uint64_t)(*in & 127);
	} while (*in++ & 128);

	return r;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main()
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
	uint8_t s[10];
	uint64_t x[] = { 0x7f, 0x4000, 0, 0x3ffffe, 0x1fffff, 0x200000, 0x3311a1234df31413ULL};

	int i, j;
	for (j = 0; j < sizeof(x)/8; j++) {
		to_seq(x[j], s);
		printf("seq from %llx: [ ", x[j]);

		i = 0;
		do { printf("%02x ", s[i]); } while ((s[i++] & 128));
		printf("] back: %llx\n", from_seq(s));
	}

	return 0;
}