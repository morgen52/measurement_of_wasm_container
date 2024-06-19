#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isBal(const char*s,int l){
    signed c=0;
    while(l--)
	if(s[l]==']') ++c;
	else if(s[l]=='[') if(--c<0) break;
    return !c;
}

void shuffle(char*s,int h){
    int x,t,i=h;
    while(i--){
	t=s[x=rand()%h];
	s[x]=s[i];
	s[i]=t;
    }
}

void genSeq(char*s,int n){
    if(n){
	memset(s,'[',n);
	memset(s+n,']',n);
	shuffle(s,n*2);
    }
    s[n*2]=0;
}

void doSeq(int n){
    char s[64];
    const char *o="False";
    genSeq(s,n);
    if(isBal(s,n*2)) o="True";
    printf("'%s': %s\n",s,o);
}

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main(){
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
    int n=0;
    while(n<9) doSeq(n++);
    return 0;
}