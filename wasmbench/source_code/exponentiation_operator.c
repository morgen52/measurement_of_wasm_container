#include <stdio.h>
#include <assert.h>

int ipow(int base, int exp)
{
   int pow = base;
   int v = 1;
   if (exp < 0) {
      assert (base != 0);  /* divide by zero */
      return (base*base != 1)? 0: (exp&1)? base : 1;
   }
       
   while(exp > 0 )
   {
      if (exp & 1) v *= pow;
      pow *= pow;
      exp >>= 1;
    }
   return v;
}

double dpow(double base, int exp)
{
   double v=1.0;
   double pow = (exp <0)? 1.0/base : base;
   if (exp < 0) exp = - exp;

   while(exp > 0 )
   {
      if (exp & 1) v *= pow;
      pow *= pow;
      exp >>= 1;
   }
   return v;
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
    printf("2^6 = %d\n", ipow(2,6));
    printf("2^-6 = %d\n", ipow(2,-6));
    printf("2.71^6 = %lf\n", dpow(2.71,6));
    printf("2.71^-6 = %lf\n", dpow(2.71,-6));
}