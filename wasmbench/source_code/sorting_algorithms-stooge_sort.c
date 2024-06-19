#include <stdio.h>

#define SWAP(r,s)  do{ t=r; r=s; s=t; } while(0)

void StoogeSort(int a[], int i, int j) 
{
   int t;
   
   if (a[j] < a[i]) SWAP(a[i], a[j]);
   if (j - i > 1)
   {
       t = (j - i + 1) / 3;
       StoogeSort(a, i, j - t);
       StoogeSort(a, i + t, j);
       StoogeSort(a, i, j - t);
   }
}
  
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char *argv[])
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
   int nums[] = {1, 4, 5, 3, -6, 3, 7, 10, -2, -5, 7, 5, 9, -3, 7};
   int i, n;
  
   n = sizeof(nums)/sizeof(int);
   StoogeSort(nums, 0, n-1);
   
   for(i = 0; i <= n-1; i++)
      printf("%5d", nums[i]);
   
   return 0;
}