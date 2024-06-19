
#include<stdio.h>

void generateGaps(unsigned long long int start,int count){
    
    int counter = 0;
    unsigned long long int i = start;
    char str[100];
    
    printf("\nFirst %d Gapful numbers >= %llu :\n",count,start);

    while(counter<count){
        sprintf(str,"%llu",i);
        if((i%(10*(str[0]-'0') + i%10))==0L){
            printf("\n%3d : %llu",counter+1,i);
            counter++;
        }
        i++;
    }
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
    unsigned long long int i = 100;
    int count = 0;
    char str[21];

    generateGaps(100,30);
    printf("\n");
    generateGaps(1000000,15);
    printf("\n");
    generateGaps(1000000000,15);
    printf("\n");

    return 0;
}
