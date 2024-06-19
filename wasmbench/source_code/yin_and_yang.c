#include <stdio.h>

void draw_yinyang(int trans, double scale)
{
	printf("<use xlink:href='#y' transform='translate(%d,%d) scale(%g)'/>",
		trans, trans, scale);
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
	
	
	printf(
	"<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n"
	"<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 1.1//EN'\n"
	"	'http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd'>\n"
	"<svg xmlns='http://www.w3.org/2000/svg' version='1.1'\n"
	"	xmlns:xlink='http://www.w3.org/1999/xlink'\n"
	"		width='30' height='30'>\n"
	"	<defs><g id='y'>\n"
	"		<circle cx='0' cy='0' r='200' stroke='black'\n"
	"			fill='white' stroke-width='1'/>\n"
	"		<path d='M0 -200 A 200 200 0 0 0 0 200\n"
	"			100 100 0 0 0 0 0 100 100 0 0 1 0 -200\n"
	"			z' fill='black'/>\n"
	"		<circle cx='0' cy='100' r='33' fill='white'/>\n"
	"		<circle cx='0' cy='-100' r='33' fill='black'/>\n"
	"	</g></defs>\n");
	draw_yinyang(20, .05);
	draw_yinyang(8, .02);
	printf("</svg>");
	return 0;
}