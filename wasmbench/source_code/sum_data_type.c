
#include<stdio.h>

typedef union data{
        int i;
        float f;
        char c;
}united;

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
        united udat;

        udat.i = 5;
        udat.f = 3.14159;
        udat.c = 'C';

        printf("Integer   i = %d , address of i = %p\n",udat.i,&udat.i);
        printf("Float     f = %f , address of f = %p\n",udat.f,&udat.f);
        printf("Character c = %c , address of c = %p\n",udat.c,&udat.c);

        return 0;
}
