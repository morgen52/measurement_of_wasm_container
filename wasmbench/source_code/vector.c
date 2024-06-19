
#include<stdio.h>
#include<math.h>

#define pi M_PI

typedef struct{
	double x,y;
}vector;

vector initVector(double r,double theta){
	vector c;
	
	c.x = r*cos(theta);
	c.y = r*sin(theta);
	
	return c;
}

vector addVector(vector a,vector b){
	vector c;
	
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	
	return c;
}

vector subtractVector(vector a,vector b){
	vector c;
	
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	
	return c;
}

vector multiplyVector(vector a,double b){
	vector c;
	
	c.x = b*a.x;
	c.y = b*a.y;
	
	return c;
}

vector divideVector(vector a,double b){
	vector c;
	
	c.x = a.x/b;
	c.y = a.y/b;
	
	return c;
}

void printVector(vector a){
	printf("%lf %c %c %lf %c",a.x,140,(a.y>=0)?'+':'-',(a.y>=0)?a.y:fabs(a.y),150);
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
	vector a = initVector(3,pi/6);
	vector b = initVector(5,2*pi/3);
	
	printf("\nVector a : ");
	printVector(a);
	
	printf("\n\nVector b : ");
	printVector(b);
	
	printf("\n\nSum of vectors a and b : ");
	printVector(addVector(a,b));
	
	printf("\n\nDifference of vectors a and b : ");
	printVector(subtractVector(a,b));
	
	printf("\n\nMultiplying vector a by 3 : ");
	printVector(multiplyVector(a,3));
	
	printf("\n\nDividing vector b by 2.5 : ");
	printVector(divideVector(b,2.5));
	
	return 0;
}
