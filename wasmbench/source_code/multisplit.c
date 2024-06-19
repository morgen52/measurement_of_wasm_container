#include <stdio.h>
#include <string.h>

void parse_sep(const char *str, const char *const *pat, int len)
{
	int i, slen;
	while (*str != '\0') {
		for (i = 0; i < len || !putchar(*(str++)); i++) {
			slen = strlen(pat[i]);
			if (strncmp(str, pat[i], slen)) continue;
			printf("{%.*s}", slen, str);
			str += slen;
			break;
		}
	}
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
	const char *seps[] = { "==", "!=", "=" };
	parse_sep("a!===b=!=c", seps, 3);

	return 0;
}