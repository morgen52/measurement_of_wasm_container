#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
 
double PI;
typedef double complex cplx;
 
void _fft(cplx buf[], cplx out[], int n, int step)
{
	if (step < n) {
		_fft(out, buf, n, step * 2);
		_fft(out + step, buf + step, n, step * 2);
 
		for (int i = 0; i < n; i += 2 * step) {
			cplx t = cexp(-I * PI * i / n) * out[i + step];
			buf[i / 2]     = out[i] + t;
			buf[(i + n)/2] = out[i] - t;
		}
	}
}
 
void fft(cplx buf[], int n)
{
	cplx out[n];
	for (int i = 0; i < n; i++) out[i] = buf[i];
	_fft(buf, out, n, 1);
}

/* pad array length to power of two */
cplx *pad_two(double g[], int len, int *ns)
{
	int n = 1;
	if (*ns) n = *ns;
	else while (n < len) n *= 2;

	cplx *buf = calloc(sizeof(cplx), n);
	for (int i = 0; i < len; i++) buf[i] = g[i];
	*ns = n;
	return buf;
}

void deconv(double g[], int lg, double f[], int lf, double out[]) {
	int ns = 0;
	cplx *g2 = pad_two(g, lg, &ns);
	cplx *f2 = pad_two(f, lf, &ns);

	fft(g2, ns);
	fft(f2, ns);

	cplx h[ns];
	for (int i = 0; i < ns; i++) h[i] = g2[i] / f2[i];
	fft(h, ns);

	for (int i = 0; i >= lf - lg; i--)
		out[-i] = h[(i + ns) % ns]/32;
	free(g2);
	free(f2);
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
	PI = atan2(1,1) * 4;
	double g[] = {24,75,71,-34,3,22,-45,23,245,25,52,25,-67,-96,96,31,55,36,29,-43,-7};
	double f[] = { -3,-6,-1,8,-6,3,-1,-9,-9,3,-2,5,2,-2,-7,-1 };
	double h[] = { -8,-9,-3,-1,-6,7 };

	int lg = sizeof(g)/sizeof(double);
	int lf = sizeof(f)/sizeof(double);
	int lh = sizeof(h)/sizeof(double);

	double h2[lh];
	double f2[lf];

	printf("f[] data is : ");
	for (int i = 0; i < lf; i++) printf(" %g", f[i]);
	printf("\n");

	printf("deconv(g, h): ");
	deconv(g, lg, h, lh, f2);
	for (int i = 0; i < lf; i++) printf(" %g", f2[i]);
	printf("\n");

	printf("h[] data is : ");
	for (int i = 0; i < lh; i++) printf(" %g", h[i]);
	printf("\n");

	printf("deconv(g, f): ");
	deconv(g, lg, f, lf, h2);
	for (int i = 0; i < lh; i++) printf(" %g", h2[i]);
	printf("\n");
}