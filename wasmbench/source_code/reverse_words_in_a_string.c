#include <stdio.h>
#include <ctype.h>

void rev_print(char *s, int n)
{
        for (; *s && isspace(*s); s++);
        if (*s) {
                char *e;
                for (e = s; *e && !isspace(*e); e++);
                rev_print(e, 0);
                printf("%.*s %d", (int)(e - s), s, n);
        }
        if (n) putchar('\n');
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
        char *s[] = {
                "---------- Ice and Fire ------------",
                "                                    ",
                "fire, in end will world the say Some",
                "ice. in say Some                    ",
                "desire of tasted I've what From     ",
                "fire. favor who those with hold I   ",
                "                                    ",
                "... elided paragraph last ...       ",
                "                                    ",
                "Frost Robert -----------------------",
                0
        };
        int i;
        for (i = 0; s[i]; i++) rev_print(s[i], 1);

        return 0;
}