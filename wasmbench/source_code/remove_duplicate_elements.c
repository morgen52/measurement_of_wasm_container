#include <stdio.h>
#include <stdlib.h>

struct list_node {int x; struct list_node *next;};
typedef struct list_node node;

node * uniq(int *a, unsigned alen)
 {if (alen == 0) return NULL;
  node *start = malloc(sizeof(node));
  if (start == NULL) exit(EXIT_FAILURE);
  start->x = a[0];
  start->next = NULL;

  for (int i = 1 ; i < alen ; ++i)
     {node *n = start;
      for (;; n = n->next)
         {if (a[i] == n->x) break;
          if (n->next == NULL)
             {n->next = malloc(sizeof(node));
              n = n->next;
              if (n == NULL) exit(EXIT_FAILURE);
              n->x = a[i];
              n->next = NULL;
              break;}}}

  return start;}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(void)
   {int a[] = {1, 2, 1, 4, 5, 2, 15, 1, 3, 4};
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
    for (node *n = uniq(a, 10) ; n != NULL ; n = n->next)
        printf("%d ", n->x);
    puts("");
    return 0;}