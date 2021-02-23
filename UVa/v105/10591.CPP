#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long n,i,sum,m,j;
	char s[15];
	while(scanf("%ld",&m)==1)
	{
		for(j=0;j<m;j++)
		{
                        scanf("%ld",&n);
        		sum=0;
			sprintf(s,"%ld",n);
			for(i=0;s[i];i++)sum+=((s[i]-'0')*(s[i]-'0'));
			while(sum/10!=0)
			{
				sprintf(s,"%ld",sum);
				sum=0;
				for(i=0;s[i];i++)sum+=((s[i]-'0')*(s[i]-'0'));
			}
			if(sum==1||sum==7)printf("Case #%ld: %ld is a Happy number.\n",j+1,n);
			else printf("Case #%ld: %ld is an Unhappy number.\n",j+1,n);
		}
	}
	return 0;
}













