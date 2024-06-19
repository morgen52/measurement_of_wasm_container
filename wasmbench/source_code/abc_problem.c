#include <stdio.h>
#include <ctype.h>

int can_make_words(char **b, char *word)
{
	int i, ret = 0, c = toupper(*word);

#define SWAP(a, b) if (a != b) { char * tmp = a; a = b; b = tmp; }

	if (!c) return 1;
	if (!b[0]) return 0;

	for (i = 0; b[i] && !ret; i++) {
		if (b[i][0] != c && b[i][1] != c) continue;
		SWAP(b[i], b[0]);
		ret = can_make_words(b + 1, word + 1);
		SWAP(b[i], b[0]);
	}

	return ret;
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
	char* blocks[] = {
		"BO", "XK", "DQ", "CP", "NA", 
		"GT", "RE", "TG", "QD", "FS", 
		"JW", "HU", "VI", "AN", "OB", 
		"ER", "FS", "LY", "PC", "ZM",
		0 };

	char *words[] = {
		"", "A", "BARK", "BOOK", "TREAT", "COMMON", "SQUAD", "Confuse", 0
	};

	char **w;
	for (w = words; *w; w++)
		printf("%s\t%d\n", *w, can_make_words(blocks, *w));

	return 0;
}