
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>

int** doublyEvenMagicSquare(int n) {
	if (n < 4 || n % 4 != 0)
		return NULL;

	int bits = 38505;
	int size = n * n;
	int mult = n / 4,i,r,c,bitPos;

	int** result = (int**)malloc(n*sizeof(int*));
	
	for(i=0;i<n;i++)
		result[i] = (int*)malloc(n*sizeof(int));

	for (r = 0, i = 0; r < n; r++) {
		for (c = 0; c < n; c++, i++) {
			bitPos = c / mult + (r / mult) * 4;
			result[r][c] = (bits & (1 << bitPos)) != 0 ? i + 1 : size - i;
		}
	}
	return result;
}

int numDigits(int n){
	int count = 1;
	
	while(n>=10){
		n /= 10;
		count++;
	}
	
	return count;
}

void printMagicSquare(int** square,int rows){
	int i,j,baseWidth = numDigits(rows*rows) + 3;
	
	printf("Doubly Magic Square of Order : %d and Magic Constant : %d\n\n",rows,(rows * rows + 1) * rows / 2);
	
	for(i=0;i<rows;i++){
		for(j=0;j<rows;j++){
			printf("%*s%d",baseWidth - numDigits(square[i][j]),"",square[i][j]);
		}
		printf("\n");
	}
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(int argC,char* argV[])
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
	int n;
	
	if(argC!=2||isdigit(argV[1][0])==0)
		printf("Usage : %s <integer specifying rows in magic square>",argV[0]);
	else{
		n = atoi(argV[1]);
		printMagicSquare(doublyEvenMagicSquare(n),n);
	}
	return 0;
}
