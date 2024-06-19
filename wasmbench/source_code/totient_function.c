
/*Abhishek Ghosh, 7th December 2018*/

#include<stdio.h>

int totient(int n){
	int tot = n,i;
	
	for(i=2;i*i<=n;i+=2){
		if(n%i==0){
			while(n%i==0)
				n/=i;
			tot-=tot/i;
		}
		
		if(i==2)
			i=1;
	}
	
	if(n>1)
		tot-=tot/n;
	
	return tot;
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
	int count = 0,n,tot;
	
	printf(" n    %c   prime",237);
        printf("\n---------------\n");
	
	for(n=1;n<=25;n++){
		tot = totient(n);
		
		if(n-1 == tot)
			count++;
		
		printf("%2d   %2d   %s\n", n, tot, n-1 == tot?"True":"False");
	}
	
	printf("\nNumber of primes up to %6d =%4d\n", 25,count);
	
	for(n = 26; n <= 100000; n++){
        tot = totient(n);
        if(tot == n-1)
			count++;
        
        if(n == 100 || n == 1000 || n%10000 == 0){
            printf("\nNumber of primes up to %6d = %4d\n", n, count);
        }
    }
	
	return 0;
}
