#include <string.h>
#include <stdio.h>

int luhn(const char* cc)
{
	const int m[] = {0,2,4,6,8,1,3,5,7,9}; // mapping for rule 3
	int i, odd = 1, sum = 0;

	for (i = strlen(cc); i--; odd = !odd) {
		int digit = cc[i] - '0';
		sum += odd ? digit : m[digit];
	}

	return sum % 10 == 0;
}

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
	const char* cc[] = {
		"49927398716",
		"49927398717",
		"1234567812345678",
		"1234567812345670",
		0
	};
	int i;

	for (i = 0; cc[i]; i++)
		printf("%16s\t%s\n", cc[i], luhn(cc[i]) ? "ok" : "not ok");

	return 0;
}