#include <stdio.h>

struct ModularArithmetic {
    int value;
    int modulus;
};

struct ModularArithmetic make(const int value, const int modulus) {
    struct ModularArithmetic r = { value % modulus, modulus };
    return r;
}

struct ModularArithmetic add(const struct ModularArithmetic a, const struct ModularArithmetic b) {
    return make(a.value + b.value, a.modulus);
}

struct ModularArithmetic addi(const struct ModularArithmetic a, const int v) {
    return make(a.value + v, a.modulus);
}

struct ModularArithmetic mul(const struct ModularArithmetic a, const struct ModularArithmetic b) {
    return make(a.value * b.value, a.modulus);
}

struct ModularArithmetic pow(const struct ModularArithmetic b, int pow) {
    struct ModularArithmetic r = make(1, b.modulus);
    while (pow-- > 0) {
        r = mul(r, b);
    }
    return r;
}

void print(const struct ModularArithmetic v) {
    printf("ModularArithmetic(%d, %d)", v.value, v.modulus);
}

struct ModularArithmetic f(const struct ModularArithmetic x) {
    return addi(add(pow(x, 100), x), 1);
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
    struct ModularArithmetic input = make(10, 13);
    struct ModularArithmetic output = f(input);

    printf("f(");
    print(input);
    printf(") = ");
    print(output);
    printf("\n");

    return 0;
}