#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
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
	char s[100];
	unsigned long two[33],i;
	int sum;
        two[0]=1;
	for(i=1;i<32;i++)two[i]=two[i-1]*2;
	while(gets(s))
	{
		if(s[0]=='0'&&s[1]=='\0')break;
		rev(s);
		sum=0;
		for(i=0;s[i];i++)sum+=((s[i]-'0')*(two[i+1]-1));
		printf("%d\n",sum);
	}
	return 0;
}













