//simulation
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int t,n,b,i,j,k,l,mod,temp,c;
	while(scanf("%ld",&t)==1)
	{
		for(i=0;i<t;i++)
		{
                	mod=0;
			scanf("%d%d",&n,&b);
			for(j=0;j<b;j++)
			{
				scanf("%d",&k);
				for(l=0,temp=1;l<k;l++)
				{
					scanf("%d",&c);
					c%=n;
					temp*=c;
					temp%=n;
				}
				mod+=temp;
                                mod%=n;
			}
			printf("%d\n",mod%n);
		}
	}
	return 0;
}













