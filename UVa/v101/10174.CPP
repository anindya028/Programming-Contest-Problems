#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
int main()
{
	char s[30];
	long i,m,n,ans;
	while(gets(s))
	{
		for(i=0;isdigit(s[i]);i++);
		if(s[i]==' ')
		{
			sscanf(s,"%ld%ld",&m,&n);
			if(n%4<2)ans=n/4;
			else ans=n/4+1;
			m--;
			if(m%4<2)ans-=(m/4);
                        else ans-=(m/4+1);
                        printf("%ld\n",ans);
		}
		else
		{
			sscanf(s,"%ld",&n);
			if(n%2==0)
			{
				if(n%4==0)
				{
					printf("%ld %ld\n",n/4+1,n/4-1);
				}
				else printf("Bachelor Number.\n");
			}
			else printf("%ld %ld\n",(n-1)/2+1,(n-1)/2);
		}
        }
	return 0;
}













