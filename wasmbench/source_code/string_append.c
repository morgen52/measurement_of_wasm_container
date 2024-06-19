#include<stdio.h>
#include<string.h>

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
    char str[24]="Good Morning";
    char *cstr=" to all";
    char *cstr2=" !!!";
    int x=0;
    //failure when space allocated to str is insufficient.

    if(sizeof(str)>strlen(str)+strlen(cstr)+strlen(cstr2))
            {
                /* 1st method*/
                strcat(str,cstr);

                /*2nd method*/
                x=strlen(str);
                sprintf(&str[x],"%s",cstr2);

                printf("%s\n",str);

            }
    return 0;
}