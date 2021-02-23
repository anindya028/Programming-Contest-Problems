#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[200];
void rev(int start,int end)
{
	int i=start,j=end;
	char temp;
	while(i<j)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
		i++;
		j--;
	}
	return;
}
int main()
{
	int g,i,len;
	while(scanf("%d",&g)==1)
	{
		if(!g)break;
		scanf("%s",s);
		len=strlen(s);
		g=len/g;
		for(i=0;i<len;i+=g)
		{
			rev(i,i+g-1);
		}
		printf("%s\n",s);
	}
	return 0;
}













