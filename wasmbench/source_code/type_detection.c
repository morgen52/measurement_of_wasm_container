
#include<stdio.h>
#include<ctype.h>

void typeDetector(char* str){	
	if(isalnum(str[0])!=0)
		printf("\n%c is alphanumeric",str[0]);
	if(isalpha(str[0])!=0)
		printf("\n%c is alphabetic",str[0]);
	if(iscntrl(str[0])!=0)
		printf("\n%c is a control character",str[0]);
	if(isdigit(str[0])!=0)
		printf("\n%c is a digit",str[0]);
	if(isprint(str[0])!=0)
		printf("\n%c is printable",str[0]);
	if(ispunct(str[0])!=0)
		printf("\n%c is a punctuation character",str[0]);
	if(isxdigit(str[0])!=0)
		printf("\n%c is a hexadecimal digit",str[0]);
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argC, char* argV[])
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
	
	if(argC==1)
		printf("Usage : %s <followed by ASCII characters>");
	else{
		for(i=1;i<argC;i++)
			typeDetector(argV[i]);
	}
	return 0;
}
