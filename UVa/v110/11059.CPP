#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	 long long max,num[19],maxpos[19],maxneg[19];
	 int i,n,cs=0;
	 num[0]=maxpos[0]=maxneg[0]=0;
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			if(!num[i])
			{
				maxpos[i]=maxneg[i]=0;
			}
			else if(num[i]>0)
			{
				if(maxpos[i-1])maxpos[i]=maxpos[i-1]*num[i];
				else maxpos[i]=num[i];
				if(maxneg[i-1])maxneg[i]=maxneg[i-1]*num[i];
				else maxneg[i]=0;
			}
			else
			{
				if(maxneg[i-1])maxpos[i]=maxneg[i-1]*num[i];
				else maxpos[i]=0;
				if(maxpos[i-1])maxneg[i]=maxpos[i-1]*num[i];
				else maxneg[i]=num[i];
			}
		}
		for(i=max=0;i<=n;i++)
				if(maxpos[i]>max)max=maxpos[i];
		printf("Case #%d: The maximum product is %lld.\n\n",++cs,max);
	}
	return 0;
}













