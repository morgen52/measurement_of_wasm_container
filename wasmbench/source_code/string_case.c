/* Demonstrate toupper and tolower for 
   standard C strings.
   This does not work for multibyte character sets. */
#include <ctype.h>
#include <stdio.h>

/* upper-cases s in place */
void str_toupper(char *s)
{
    while(*s)
    {
        *s=toupper(*s);
        s++;
    }
}


/* lower-cases s in place */
void str_tolower(char *s)
{
    while(*s)
    {
        *s=tolower(*s);
        s++;
    }
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char *argv[])
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
    char t[255]="alphaBETA";
    str_toupper(t);
    printf("uppercase: %s\n", t);
    str_tolower(t);
    printf("lowercase: %s\n", t);
    return 0;
}