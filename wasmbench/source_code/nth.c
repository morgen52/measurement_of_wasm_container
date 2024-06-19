#include <stdio.h>
 
char* addSuffix(int num, char* buf, size_t len)
{
    char *suffixes[4] = { "th", "st", "nd", "rd" };
    int i;

    switch (num % 10)
    {
        case 1 : i = (num % 100 == 11) ? 0 : 1;
	         break;
        case 2 : i = (num % 100 == 12) ? 0 : 2;
                 break;
        case 3 : i = (num % 100 == 13) ? 0 : 3;
                 break;
        default: i = 0;
    };
 
    snprintf(buf, len, "%d%s", num, suffixes[i]);
    return buf;
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
    int i;

    printf("Set [0,25]:\n");
    for (i = 0; i < 26; i++)
    {
        char s[5];
        printf("%s ", addSuffix(i, s, 5));
    }
    putchar('\n'); 

    printf("Set [250,265]:\n");
    for (i = 250; i < 266; i++)
    {
        char s[6];
        printf("%s ", addSuffix(i, s, 6));
    }
    putchar('\n'); 

    printf("Set [1000,1025]:\n");
    for (i = 1000; i < 1026; i++)
    {
        char s[7];
        printf("%s ", addSuffix(i, s, 7));
    }
    putchar('\n');

    return 0;
}