#include <math.h>
#include <stdio.h>

const char* animals[] = { "Rat","Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig" };
const char* elements[] = { "Wood","Fire","Earth","Metal","Water" };

const char* getElement(int year) {
    int element = (int)floor((year - 4) % 10 / 2);
    return elements[element];
}

const char* getAnimal(int year) {
    return animals[(year - 4) % 12];
}

const char* getYY(int year) {
    if (year % 2 == 0) {
        return "yang";
    } else {
        return "yin";
    }
}

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
    int years[] = { 1935, 1938, 1968, 1972, 1976, 2017 };
    int i;

    //the zodiac cycle didnt start until 4 CE, so years <4 shouldnt be valid
    for (i = 0; i < 6; ++i) {
        int year = years[i];
        printf("%d is the year of the %s %s (%s).\n", year, getElement(year), getAnimal(year), getYY(year));
    }

    return 0;
}