#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *split(char *str);
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc,char **argv)
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
	char input[13]="gHHH5YY++///\\";
	printf("%s\n",split(input));
}
char *split(char *str)
{
	char last=*str,*result=malloc(3*strlen(str)),*counter=result;
	for (char *c=str;*c;c++) {
		if (*c!=last) {
			strcpy(counter,", ");
			counter+=2;
			last=*c;
		}
		*counter=*c;
		counter++;
	}
	*(counter--)='\0';
	return realloc(result,strlen(result));
}