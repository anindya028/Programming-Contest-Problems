#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
char s[1000];
int i,count,j;
void rev(char *t)
{
	i=0,j=strlen(t)-1;
	while(i<j)
	{
		char temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}
void bin(long n)
{
	for(i=0,count=0;n;i++)
	{
		s[i]=(n%2)+'0';
                if(s[i]=='1')count++;
		n/=2;
	}
	s[i]='\0';
	rev(s);
}
void main()
{
        long n;
	while(scanf("%ld",&n)==1)
	{
        	if(!n)break;
		bin(n);
		printf("The parity of %s is %d (mod 2).\n",s,count);
        }
}













