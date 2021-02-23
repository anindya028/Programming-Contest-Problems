#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int c,n,i,j,k,ans,l;
	while(scanf("%d",&c)==1)
	{
		for(i=0;i<c;i++)
		{
			scanf("%d",&n);
			ans=20000000;
			for(j=1;j*j*j<=n;j++)
				for(k=j;j*k*k<=n;k++)
				{
					if(n%(j*k))continue;
					l=n/(j*k);
					if(2*(l*k+k*j+j*l)<ans)
						ans=2*(l*k+k*j+j*l);
				}
			printf("%d\n",ans);
		}
	}				
	return 0;
}













