#include <stdio.h>
#include <string.h>

const char *haystack[] = {
  "Zig", "Zag", "Wally", "Ronald", "Bush", "Krusty", "Charlie",
  "Bush", "Boz", "Zag", NULL
};

int search_needle(const char *needle, const char **hs)
{
  int i = 0;
  while( hs[i] != NULL ) {
    if ( strcmp(hs[i], needle) == 0 ) return i;
    i++;
  }
  return -1;
}

int search_last_needle(const char *needle, const char **hs)
{
  int i, last=0;
  i = last = search_needle(needle, hs);
  if ( last < 0 ) return -1;
  while( hs[++i] != NULL ) {
    if ( strcmp(needle, hs[i]) == 0 ) {
      last = i;
    }
  }
  return last;
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
  printf("Bush is at %d\n", search_needle("Bush", haystack));
  if ( search_needle("Washington", haystack) == -1 )
    printf("Washington is not in the haystack\n");
  printf("First index for Zag: %d\n", search_needle("Zag", haystack));
  printf("Last index for Zag: %d\n", search_last_needle("Zag", haystack));
  return 0;
}