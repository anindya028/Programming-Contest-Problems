#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char s[50];
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
	char temp;
	while(i<j)
	{
	        temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}
int convert_to_bin(int num)
{
	int i=0,zero=0;
	while(num)
	{
		if(num%2)s[i]='1';
		else
		{
			s[i]='0';
			zero++;
		}
		num/=2;
		i++;
	}
	s[i]='\0';
	rev(s);
	return zero;
}
void leftrot(void)
{
	int i;
	char c=s[0];
	for(i=0;s[i+1];i++)
		s[i]=s[i+1];
	s[i]=c;
	return;
}
int convert_to_dec(void)
{
	int num,i;
	for(i=num=0;s[i];i++)
	{
		num=num*2+s[i]-'0';
	}
	return num;
}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		n=convert_to_bin(n);
		leftrot();
		printf("%d\n",convert_to_dec()-1);
	}
	return 0;
}













