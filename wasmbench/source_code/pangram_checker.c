#include <stdio.h>

int pangram(const char *s)
{
	int c, mask = (1 << 26) - 1;
	while ((c = (*s++)) != '\0') /* 0x20 converts lowercase to upper */
		if ((c &= ~0x20) <= 'Z' && c >= 'A')
			mask &= ~(1 << (c - 'A'));

	return !mask;
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
	int i;
	const char *s[] = {	"The quick brown fox jumps over lazy dogs.",
				"The five boxing wizards dump quickly.",  };

	for (i = 0; i < 2; i++)
		printf("%s: %s\n", pangram(s[i]) ? "yes" : "no ", s[i]);

	return 0;
}