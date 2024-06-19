
// This code is the implementation of Babbage Problem

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main() {
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
	
	
	int current = 0, 	//the current number 
	    square;		//the square of the current number

	//the strategy of take the rest of division by 1e06 is
	//to take the a number how 6 last digits are 269696
	while (((square=current*current) % 1000000 != 269696) && (square<INT_MAX)) {
		current++;
	}

        //output
	if (square>+INT_MAX)
	    printf("Condition not satisfied before INT_MAX reached.");
	else		   
	    printf ("The smallest number whose square ends in 269696 is %d\n", current);
	   
        //the end
	return 0 ;
}
