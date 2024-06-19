
#include<stdio.h>
 
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
    int i,j;
 
    char days[12][10] = 
    {
        "First",
        "Second",
        "Third",
        "Fourth",
        "Fifth",
        "Sixth",
        "Seventh",
        "Eighth",
        "Ninth",
        "Tenth",
        "Eleventh",
        "Twelfth"
    };

    char gifts[12][33] =
    {
        "Twelve drummers drumming",
        "Eleven pipers piping",
        "Ten lords a-leaping",
        "Nine ladies dancing",
        "Eight maids a-milking",
        "Seven swans a-swimming",
        "Six geese a-laying",
        "Five golden rings",
        "Four calling birds",
        "Three french hens", 
        "Two turtle doves", 
        "And a partridge in a pear tree."
    };
 
    for(i=0;i<12;i++)
    {
        printf("\n\nOn the %s day of Christmas\nMy true love gave to me:",days[i]);
 
        for(j=i;j>=0;j--)
        {
            (i==0)?printf("\nA partridge in a pear tree."):printf("\n%s%c",gifts[11-j],(j!=0)?',':' ');
        }
    }
 
    return 0;
}