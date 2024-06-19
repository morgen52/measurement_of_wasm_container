

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

float mean(float* arr,int size){
	int i = 0;
	float sum = 0;
	
	while(i != size)
		sum += arr[i++];
	
	return sum/size;
}

float variance(float reference,float* arr, int size){
	int i=0;
	float* newArr = (float*)malloc(size*sizeof(float));
	
	for(;i<size;i++)
		newArr[i] = (reference - arr[i])*(reference - arr[i]);
	
	return mean(newArr,size);
}

float* extractData(char* str, int *len){
	float* arr;
	int i=0,count = 1;
	char* token;
	
	while(str[i]!=00){
		if(str[i++]==',')
			count++;
	}
	
	arr = (float*)malloc(count*sizeof(float));
	*len = count;
	
	token = strtok(str,",");
	
	i = 0;
	
	while(token!=NULL){
		arr[i++] = atof(token);
		token = strtok(NULL,",");
	}
	
	return arr;
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
	float* arr,reference,meanVal;
	int len;
	if(argC!=3)
		printf("Usage : %s <reference value> <observations separated by commas>");
	else{
		arr = extractData(argV[2],&len);
		
		reference = atof(argV[1]);
		
		meanVal = mean(arr,len);

		printf("Average Error : %.9f\n",variance(reference,arr,len));
		printf("Crowd Error : %.9f\n",(reference - meanVal)*(reference - meanVal));
		printf("Diversity : %.9f",variance(meanVal,arr,len));
	}
	
	return 0;
}
