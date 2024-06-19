#include<stdio.h>

typedef struct{
	int integer;
	float decimal;
	char letter;
	char string[100];
	double bigDecimal;
}Composite;

Composite example()
{
	Composite C = {1, 2.3, 'a', "Hello World", 45.678};
	return C;
}


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
	Composite C = example();

	printf("Values from a function returning a structure : { %d, %f, %c, %s, %f}\n", C.integer, C.decimal, C.letter, C.string, C.bigDecimal);

	return 0;
}