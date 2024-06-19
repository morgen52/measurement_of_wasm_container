
#include<stdio.h>

typedef struct{
	int num,den;
	}fraction;

fraction examples[] = {{1,2}, {3,1}, {23,8}, {13,11}, {22,7}, {-151,77}}; 
fraction sqrt2[] = {{14142,10000}, {141421,100000}, {1414214,1000000}, {14142136,10000000}};
fraction pi[] = {{31,10}, {314,100}, {3142,1000}, {31428,10000}, {314285,100000}, {3142857,1000000}, {31428571,10000000}, {314285714,100000000}};

int r2cf(int *numerator,int *denominator)
{
	int quotient=0,temp;
	
	if(denominator != 0)
	{
		quotient = *numerator / *denominator;
		
		temp = *numerator;
		
		*numerator = *denominator;
		
		*denominator = temp % *denominator;
	}
	
	return quotient;
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
	int i;
	
	printf("Running the examples :");
	
	for(i=0;i<sizeof(examples)/sizeof(fraction);i++)
	{
		printf("\nFor N = %d, D = %d :",examples[i].num,examples[i].den);
		
		while(examples[i].den != 0){
			printf(" %d ",r2cf(&examples[i].num,&examples[i].den));
			}
	}
	
	printf("\n\nRunning for %c2 :",251); /* 251 is the ASCII code for the square root symbol */
	
	for(i=0;i<sizeof(sqrt2)/sizeof(fraction);i++)
	{
		printf("\nFor N = %d, D = %d :",sqrt2[i].num,sqrt2[i].den);
		
		while(sqrt2[i].den != 0){
			printf(" %d ",r2cf(&sqrt2[i].num,&sqrt2[i].den));
			}
	}
	
	printf("\n\nRunning for %c :",227); /* 227 is the ASCII code for Pi's symbol */
	
	for(i=0;i<sizeof(pi)/sizeof(fraction);i++)
	{
		printf("\nFor N = %d, D = %d :",pi[i].num,pi[i].den);
		
		while(pi[i].den != 0){
			printf(" %d ",r2cf(&pi[i].num,&pi[i].den));
			}
	}
	
	
	
	return 0;
}
				
