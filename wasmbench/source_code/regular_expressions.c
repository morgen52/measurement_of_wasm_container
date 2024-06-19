#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>
#include <string.h>

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
   regex_t preg;
   regmatch_t substmatch[1];
   const char *tp = "string$";
   const char *t1 = "this is a matching string";
   const char *t2 = "this is not a matching string!";
   const char *ss = "istyfied";
   
   regcomp(&preg, "string$", REG_EXTENDED);
   printf("'%s' %smatched with '%s'\n", t1,
                                        (regexec(&preg, t1, 0, NULL, 0)==0) ? "" : "did not ", tp);
   printf("'%s' %smatched with '%s'\n", t2,
                                        (regexec(&preg, t2, 0, NULL, 0)==0) ? "" : "did not ", tp);
   regfree(&preg);
   /* change "a[a-z]+" into "istifyed"?*/
   regcomp(&preg, "a[a-z]+", REG_EXTENDED);
   if ( regexec(&preg, t1, 1, substmatch, 0) == 0 )
   {
      //fprintf(stderr, "%d, %d\n", substmatch[0].rm_so, substmatch[0].rm_eo);
      char *ns = malloc(substmatch[0].rm_so + 1 + strlen(ss) +
                        (strlen(t1) - substmatch[0].rm_eo) + 2);
      memcpy(ns, t1, substmatch[0].rm_so+1);
      memcpy(&ns[substmatch[0].rm_so], ss, strlen(ss));
      memcpy(&ns[substmatch[0].rm_so+strlen(ss)], &t1[substmatch[0].rm_eo],
                strlen(&t1[substmatch[0].rm_eo]));
      ns[ substmatch[0].rm_so + strlen(ss) +
          strlen(&t1[substmatch[0].rm_eo]) ] = 0;
      printf("mod string: '%s'\n", ns);
      free(ns); 
   } else {
      printf("the string '%s' is the same: no matching!\n", t1);
   }
   regfree(&preg);
   
   return 0;
}