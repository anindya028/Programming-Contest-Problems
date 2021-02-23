#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
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
	int n,i,num,zero,count;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		zero=convert_to_bin(num);
		count=0;
		while(zero)
		{
			leftrot();
			num=convert_to_dec();
			zero=convert_to_bin(num);
			count++;
		}
		printf("Case %d: %d %d\n",i+1,count,num);
	}
	return 0;
}













