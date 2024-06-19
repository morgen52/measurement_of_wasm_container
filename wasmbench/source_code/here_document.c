
#include<stdio.h>

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
    printf("\nThe Heredoc task was marked not implementable in C.\
    \nFrankly the person who did so seems to have little idea of what C\
    is capable of.\n\
    After all, what would one call this multiline printf statement ?\
    I may be old, but do not forget that it all started with me.\
    \n\nEver enigmatic...\n\
    C   ");
    
    return 0;
}
