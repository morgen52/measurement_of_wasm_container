#include <math.h>
#include <stdio.h>
#include <limits.h>
#pragma precision=log10l(ULLONG_MAX)/2

typedef enum { FALSE=0, TRUE=1 } BOOL;

BOOL is_prime( int p ){
  if( p == 2 ) return TRUE;
  else if( p <= 1 || p % 2 == 0 ) return FALSE;
  else {
    BOOL prime = TRUE;
    const int to = sqrt(p);
    int i;
    for(i = 3; i <= to; i+=2)  
      if (!(prime = p % i))break;
    return prime;
  }
}

BOOL is_mersenne_prime( int p ){
  if( p == 2 ) return TRUE;
  else {
    const long long unsigned m_p = ( 1LLU << p ) - 1;
    long long unsigned s = 4;
    int i;
    for (i = 3; i <= p; i++){
      s = (s * s - 2) % m_p;
    }
    return s == 0;
  }
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char **argv){
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

  const int upb = log2l(ULLONG_MAX)/2; 
  int p;
  printf(" Mersenne primes:\n");
  for( p = 2; p <= upb; p += 1 ){
    if( is_prime(p) && is_mersenne_prime(p) ){
      printf (" M%u",p);
    }
  }
  printf("\n");
}