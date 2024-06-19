#include <math.h>
#include <stdio.h>

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
  double pi = 4 * atan(1);
  /*Pi / 4 is 45 degrees. All answers should be the same.*/
  double radians = pi / 4;
  double degrees = 45.0;
  double temp;
  /*sine*/
  printf("%f %f\n", sin(radians), sin(degrees * pi / 180));
  /*cosine*/
  printf("%f %f\n", cos(radians), cos(degrees * pi / 180));
  /*tangent*/
  printf("%f %f\n", tan(radians), tan(degrees * pi / 180));
  /*arcsine*/
  temp = asin(sin(radians));
  printf("%f %f\n", temp, temp * 180 / pi);
  /*arccosine*/
  temp = acos(cos(radians));
  printf("%f %f\n", temp, temp * 180 / pi);
  /*arctangent*/
  temp = atan(tan(radians));
  printf("%f %f\n", temp, temp * 180 / pi);

  return 0;
}