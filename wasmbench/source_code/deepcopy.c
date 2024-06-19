
#include<stdio.h>

typedef struct{
	int a;
}layer1;

typedef struct{
	layer1 l1;
	float b,c;
}layer2;

typedef struct{
	layer2 l2;
	layer1 l1;
	int d,e;
}layer3;

void showCake(layer3 cake){
	printf("\ncake.d = %d",cake.d);
	printf("\ncake.e = %d",cake.e);
	printf("\ncake.l1.a = %d",cake.l1.a);
	printf("\ncake.l2.b = %f",cake.l2.b);
	printf("\ncake.l2.l1.a = %d",cake.l2.l1.a);
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
	layer3 cake1,cake2;
	
	cake1.d = 1;
	cake1.e = 2;
	cake1.l1.a = 3;
	cake1.l2.b = 4;
	cake1.l2.l1.a = 5;
	
	printf("Cake 1 is : ");
	showCake(cake1);
	
	cake2 = cake1;
	
	cake2.l2.b += cake2.l2.l1.a;
	
	printf("\nCake 2 is : ");
	showCake(cake2);
	
	return 0;
}
