/*
The function anynacci determines the n-arity of the sequence from the number of seed elements. 0 ended arrays are used since C does not have a way of determining the length of dynamic and function-passed integer arrays.*/

#include<stdlib.h>
#include<stdio.h>

int *
anynacci (int *seedArray, int howMany)
{
  int *result = malloc (howMany * sizeof (int));
  int i, j, initialCardinality;

  for (i = 0; seedArray[i] != 0; i++);
  initialCardinality = i;

  for (i = 0; i < initialCardinality; i++)
    result[i] = seedArray[i];

  for (i = initialCardinality; i < howMany; i++)
    {
      result[i] = 0;
      for (j = i - initialCardinality; j < i; j++)
        result[i] += result[j];
    }
  return result;
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main ()
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
  int fibo[] = { 1, 1, 0 }, tribo[] = { 1, 1, 2, 0 }, tetra[] = { 1, 1, 2, 4, 0 }, luca[] = { 2, 1, 0 };
  int *fibonacci = anynacci (fibo, 10), *tribonacci = anynacci (tribo, 10), *tetranacci = anynacci (tetra, 10), 
      *lucas = anynacci(luca, 10);
  int i;

  printf ("\nFibonacci\tTribonacci\tTetranacci\tLucas\n");

  for (i = 0; i < 10; i++)
    printf ("\n%d\t\t%d\t\t%d\t\t%d", fibonacci[i], tribonacci[i],
            tetranacci[i], lucas[i]);

  return 0;
}