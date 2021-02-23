#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define eps 1e-12

int main()
{
	int i,min,ans,sum,j,m;
	double d;
	char s[100];
	while(scanf("%s",s)==1)
	{
		if(s[0]=='0' && s[1]=='\0')
			break;
		min=0;
		for(i=0;s[i];i++)
			if((s[i]-'0')>min)
				min=s[i]-'0';
		for(i=min+1;i<101;i++)
		{
			sum=0;
			for(j=strlen(s)-1,m=1;j>=0;j--)
			{
				sum+=(s[j]-'0')*m;
				m*=i;
			}
			d=sqrt(sum);
			if((d-(int)(d))<eps)
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}













