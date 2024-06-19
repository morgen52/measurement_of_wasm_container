#include<math.h>
#include<stdio.h>

double
meanAngle (double *angles, int size)
{
  double y_part = 0, x_part = 0;
  int i;

  for (i = 0; i < size; i++)
    {
      x_part += cos (angles[i] * M_PI / 180);
      y_part += sin (angles[i] * M_PI / 180);
    }

  return atan2 (y_part / size, x_part / size) * 180 / M_PI;
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
  double angleSet1[] = { 350, 10 };
  double angleSet2[] = { 90, 180, 270, 360};
  double angleSet3[] = { 10, 20, 30};

  printf ("\nMean Angle for 1st set : %lf degrees", meanAngle (angleSet1, 2));
  printf ("\nMean Angle for 2nd set : %lf degrees", meanAngle (angleSet2, 4));
  printf ("\nMean Angle for 3rd set : %lf degrees\n", meanAngle (angleSet3, 3));
  return 0;
}