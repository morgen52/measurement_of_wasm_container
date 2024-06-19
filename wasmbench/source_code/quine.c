#include <stdio.h>

static char sym[] = "\n\t\\\"";

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(void) {
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
	const char *code = "#include <stdio.h>%c%cstatic char sym[] = %c%cn%ct%c%c%c%c%c;%c%cint main(void) {%c%cconst char *code = %c%s%c;%c%cprintf(code, sym[0], sym[0], sym[3], sym[2], sym[2], sym[2], sym[2], sym[2], sym[3], sym[3], sym[0], sym[0], sym[0], sym[1], sym[3], code, sym[3], sym[0], sym[1], sym[0], sym[0], sym[1], sym[0], sym[0]);%c%c%creturn 0;%c}%c";
	printf(code, sym[0], sym[0], sym[3], sym[2], sym[2], sym[2], sym[2], sym[2], sym[3], sym[3], sym[0], sym[0], sym[0], sym[1], sym[3], code, sym[3], sym[0], sym[1], sym[0], sym[0], sym[1], sym[0], sym[0]);

	return 0;
}
