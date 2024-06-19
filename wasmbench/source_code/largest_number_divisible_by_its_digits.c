
#include<stdio.h>

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
	int num = 9876432,diff[] = {4,2,2,2},i,j,k=0;
	char str[10];
	
		start:snprintf(str,10,"%d",num);

		for(i=0;str[i+1]!=00;i++){
			if(str[i]=='0'||str[i]=='5'||num%(str[i]-'0')!=0){
				num -= diff[k];
				k = (k+1)%4;
				goto start;
			}
			for(j=i+1;str[j]!=00;j++)
				if(str[i]==str[j]){
					num -= diff[k];
					k = (k+1)%4;
					goto start;
			}
		}	
	
	printf("Number found : %d",num);
	return 0;
}
