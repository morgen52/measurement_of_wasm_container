#include <stdio.h>

int check_isbn13(const char *isbn) {
    int ch = *isbn, count = 0, sum = 0;
    /* check isbn contains 13 digits and calculate weighted sum */
    for ( ; ch != 0; ch = *++isbn, ++count) {
        /* skip hyphens or spaces */
        if (ch == ' ' || ch == '-') {
            --count;
            continue;
        }
        if (ch < '0' || ch > '9') {
            return 0;
        }
        if (count & 1) {
            sum += 3 * (ch - '0');
        } else {
            sum += ch - '0';
        }
    }
    if (count != 13) return 0;
    return !(sum%10);
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
    int i;
    const char* isbns[] = {"978-1734314502", "978-1734314509", "978-1788399081", "978-1788399083"};
    for (i = 0; i < 4; ++i) {
        printf("%s: %s\n", isbns[i], check_isbn13(isbns[i]) ? "good" : "bad");
    }
    return 0;
}