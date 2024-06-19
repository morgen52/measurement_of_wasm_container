#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h> // for uintptr_t

const char * const_str = "global const string";

__attribute__((noinline))
void leaf(char * arg_str, char * stack_str, char * heap_str) {
  int stack_callee = 42;

  printf("  in leaf()\n");

  printf("    %s, addr: %p (%lu)\n", const_str, const_str, (uintptr_t) const_str);
  printf("    %s, addr: %p (%lu)\n", stack_str, stack_str, (uintptr_t) stack_str);
  printf("    stack value in leaf() function, addr: %p (%lu)\n", &stack_callee, (uintptr_t) &stack_callee);
  printf("    stack grows: %ld\n", ((void*) &stack_callee) - ((void*) stack_str));
  printf("    %s, addr: %p (%lu)\n", heap_str, heap_str, (uintptr_t) heap_str);
  printf("    argv[0]: %s, addr: %p (%lu)\n", arg_str, arg_str, (uintptr_t) arg_str);
}

__attribute__((noinline))
void intermediate(char * arg_str) {
  char stack_str[64];
  strcpy(stack_str, "stack-allocated (local) string");
  
  char * heap_str = (char*) malloc(64*sizeof(char));
  strcpy(heap_str, "dynamically (heap) allocated string");

  printf("  in intermediate()\n");
  leaf(arg_str, stack_str, heap_str);
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argc, char **argv) {
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
  printf("  in main()\n");
  intermediate(argv[0]);
  return 0;
}
