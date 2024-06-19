#include <stdio.h>
#include <stdlib.h>

double kelvinToCelsius(double k){
    return k - 273.15;
}

double kelvinToFahrenheit(double k){
    return k * 1.8 - 459.67;
}

double kelvinToRankine(double k){
    return k * 1.8;
}
void convertKelvin(double kelvin) {
    printf("K %.2f\n", kelvin);
    printf("C %.2f\n", kelvinToCelsius(kelvin));
    printf("F %.2f\n", kelvinToFahrenheit(kelvin));
    printf("R %.2f", kelvinToRankine(kelvin));
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, const char * argv[])
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
    if (argc > 1) {
        double kelvin = atof(argv[1]);
        convertKelvin(kelvin);
    }
    return 0;
}