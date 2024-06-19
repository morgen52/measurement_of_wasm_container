
/* Include statements and constant definitions */
#include <stdio.h>
#define HIGHEST_DEGREE 5
#define LARGEST_NUMBER 10

/* Recursive implementation of multifactorial function */
int multifact(int n, int deg){
   return n <= deg ? n : n * multifact(n - deg, deg);
}

/* Iterative implementation of multifactorial function */
int multifact_i(int n, int deg){
   int result = n;
   while (n >= deg + 1){
      result *= (n - deg);
      n -= deg;
   }
   return result;
}

/* Test function to print out multifactorials */
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(void){
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
   int i, j;
   for (i = 1; i <= HIGHEST_DEGREE; i++){
      printf("\nDegree %d: ", i);
      for (j = 1; j <= LARGEST_NUMBER; j++){
         printf("%d ", multifact(j, i));
      }
   }
}
