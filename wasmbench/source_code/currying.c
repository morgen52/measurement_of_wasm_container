
#include<stdarg.h>
#include<stdio.h>

long int factorial(int n){
	if(n>1)
		return n*factorial(n-1);
	return 1;
}

long int sumOfFactorials(int num,...){
	va_list vaList;
	long int sum = 0;
	
	va_start(vaList,num);
	
	while(num--)
		sum += factorial(va_arg(vaList,int));
	
	va_end(vaList);
	
	return sum;
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
	printf("\nSum of factorials of [1,5] : %ld",sumOfFactorials(5,1,2,3,4,5));
	printf("\nSum of factorials of [3,5] : %ld",sumOfFactorials(3,3,4,5));
	printf("\nSum of factorials of [1,3] : %ld",sumOfFactorials(3,1,2,3));
	
	return 0;
}
