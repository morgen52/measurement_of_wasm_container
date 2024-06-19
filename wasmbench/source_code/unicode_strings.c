#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* wchar_t is the standard type for wide chars; what it is internally
 * depends on the compiler.
 */
wchar_t poker[] = L"♥♦♣♠";
wchar_t four_two[] = L"\x56db\x5341\x4e8c";

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
	/* Set the locale to alert C's multibyte output routines */
	if (!setlocale(LC_CTYPE, "")) {
		fprintf(stderr, "Locale failure, check your env vars\n");
		return 1;
	}

#ifdef __STDC_ISO_10646__
	/* C99 compilers should understand these */
	printf("%lc\n", 0x2708);	/* ✈ */
	printf("%ls\n", poker);		/* ♥♦♣♠ */
	printf("%ls\n", four_two);	/* 四十二 */
#else
	/* oh well */
	printf("airplane\n");
	printf("club diamond club spade\n");
	printf("for ty two\n");
#endif
	return 0;
}