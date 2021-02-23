#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
int main()
{
	long num,i;
	char s[100];
	while(scanf("%ld",&num)==1)
	{
		if(num<0)break;
		if(!num)
		{
			printf("0\n");
			continue;	
		}
		for(i=0;num;i++)
		{
			s[i]=(num%3)+'0';
			num/=3;
		}
		s[i]=NULL;
		rev(s);
		printf("%s\n",s);
	}
	return 0;
}













