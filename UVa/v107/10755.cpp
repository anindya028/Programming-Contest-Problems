#include<stdio.h>

#define LL long long

LL mat[25][25][25];
LL sum[25][25][25];

int main()
{
	int i,j,k,t,cs,a,b,c,j1,k1;
	LL runsum,ans;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		scanf("%d%d%d",&a,&b,&c);
		for(i=1;i<=a;i++)
			for(j=1;j<=b;j++)
				for(k=1;k<=c;k++)
					scanf("%lld",&mat[i][j][k]);
		
		for(i=1;i<=a;i++)
			for(j=1;j<=b;j++)
				for(k=1;k<=c;k++)
					sum[i][j][k]=mat[i][j][k]+sum[i][j-1][k]+sum[i][j][k-1]-sum[i][j-1][k-1];
		
		ans=-(1<<30);
		ans*=-ans;

		for(j=1;j<=b;j++)
			for(j1=j;j1<=b;j1++)
				for(k=1;k<=c;k++)
					for(k1=k;k1<=c;k1++)
					{
						runsum=0;
						for(i=1;i<=a;i++)
						{
							runsum+=(sum[i][j1][k1]-sum[i][j-1][k1]-sum[i][j1][k-1]+sum[i][j-1][k-1]);
							
							if(runsum>ans)
								ans=runsum;
							if(runsum<0)
								runsum=0;
						}
					}

		printf("%lld\n",ans);
	}
	return 0;
}
