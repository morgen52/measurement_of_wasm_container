#include <stdio.h>

int check_isin(char *a) {
    int i, j, k, v, s[24];
    
    j = 0;
    for(i = 0; i < 12; i++) {
        k = a[i];
        if(k >= '0' && k <= '9') {
            if(i < 2) return 0;
            s[j++] = k - '0';
        } else if(k >= 'A' && k <= 'Z') {
            if(i == 11) return 0;
            k -= 'A' - 10;
            s[j++] = k / 10;
            s[j++] = k % 10;
        } else {
            return 0;
        }
    }
    
    if(a[i]) return 0;
    
    v = 0;
    for(i = j - 2; i >= 0; i -= 2) {
        k = 2 * s[i];
        v += k > 9 ? k - 9 : k;
    }
    
    for(i = j - 1; i >= 0; i -= 2) {
        v += s[i];
    }
    
    return v % 10 == 0;
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
    char *test[7] = {"US0378331005", "US0373831005", "U50378331005",
                     "US03378331005", "AU0000XVGZA3", "AU0000VXGZA3",
                     "FR0000988040"};
    int i;
    for(i = 0; i < 7; i++) printf("%c%c", check_isin(test[i]) ? 'T' : 'F', i == 6 ? '\n' : ' ');
    return 0;
}

/* will print: T F F F T T T */