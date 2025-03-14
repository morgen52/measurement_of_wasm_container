#include <stdio.h>
#include <time.h>

static const char *months[] = {"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};
static int long_months[] = {0, 2, 4, 6, 7, 9, 11};

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
    int n = 0, y, i, m;
    struct tm t = {0};
    printf("Months with five weekends:\n");
    for (y = 1900; y <= 2100; y++) {
        for (i = 0; i < 7; i++) {
            m = long_months[i];
            t.tm_year = y-1900;
	    t.tm_mon = m;
	    t.tm_mday = 1;
            if (mktime(&t) == -1) { /* date not supported */
                printf("Error: %d %s\n", y, months[m]);
                continue;
            }
            if (t.tm_wday == 5) { /* Friday */
                printf("  %d %s\n", y, months[m]);
                n++;
            }
        }
    }
    printf("%d total\n", n);
    return 0;
}