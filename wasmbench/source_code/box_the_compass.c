#include <stdio.h>

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
        int i, j;
        double degrees[] = { 0.0, 16.87, 16.88, 33.75, 50.62, 50.63, 67.5,
                84.37, 84.38, 101.25, 118.12, 118.13, 135.0, 151.87, 151.88,
                168.75, 185.62, 185.63, 202.5, 219.37, 219.38, 236.25, 253.12,
                253.13, 270.0, 286.87, 286.88, 303.75, 320.62, 320.63, 337.5,
                354.37, 354.38 };
        const char * names =  "North                 "
                              "North by east         "
                              "North-northeast       "
                              "Northeast by north    "
                              "Northeast             "
                              "Northeast by east     "
                              "East-northeast        "
                              "East by north         "
                              "East                  "
                              "East by south         "
                              "East-southeast        "
                              "Southeast by east     "
                              "Southeast             "
                              "Southeast by south    "
                              "South-southeast       "
                              "South by east         "
                              "South                 "
                              "South by west         "
                              "South-southwest       "
                              "Southwest by south    "
                              "Southwest             "
                              "Southwest by west     "
                              "West-southwest        "
                              "West by south         "
                              "West                  "
                              "West by north         "
                              "West-northwest        "
                              "Northwest by west     "
                              "Northwest             "
                              "Northwest by north    "
                              "North-northwest       "
                              "North by west         "
                              "North                 ";

        for (i = 0; i < 33; i++) {
                j = .5 + degrees[i] * 32 / 360;

                printf("%2d  %.22s  %6.2f\n", (j % 32) + 1, names + (j % 32) * 22,
                        degrees[i]);
        }

        return 0;
}