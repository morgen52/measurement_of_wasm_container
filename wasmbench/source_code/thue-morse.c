#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char *argv[]){
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
	char sequence[256+1] = "0";
	char inverse[256+1] = "1";
	char buffer[256+1];
	int i;
	
	for(i = 0; i < 8; i++){
		strcpy(buffer, sequence);
		strcat(sequence, inverse);
		strcat(inverse, buffer);
	}
	
	puts(sequence);
	return 0;
}