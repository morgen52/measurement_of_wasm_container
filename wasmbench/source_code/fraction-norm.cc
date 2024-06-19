// Compile with:
//   clang++ --target=wasm32-wasi fraction-norm.cc -o fraction-norm.wasm -g \
//     -O0 -fdebug-prefix-map=$PWD=.

struct Fraction {
  long numerator;
  long denominator;
};

inline long abs(long x)
{
  return x >= 0 ? x : -x;  
}

extern "C"
void norm(Fraction &n)
{
  long a = abs(n.numerator), b = abs(n.denominator);
  if (a == 0 || b == 0) return;
  do {
   a %= b;
   if (a == 0) break;
   b %= a;
  } while (b > 0);
  long gcd = a + b;
  if (n.denominator > 0) {
    n.numerator /= gcd;
    n.denominator /= gcd;
  } else {
    n.numerator /= -gcd;
    n.denominator /= -gcd;
  }
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
  Fraction c = {6, 27};
  norm(c);
  return 0;
}
