#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 100000000.
int main()
{
	int i,j,k,t,n,l,x[105],y[105];
	double mat[105][105],max;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				mat[i][j]=inf;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			for(j=1;j<=i;j++)
				if(((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]))<=100)
					mat[i][j]=mat[j][i]=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
		}
		max=0.;
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if((mat[i][k]+mat[k][j])<mat[i][j])
						mat[i][j]=mat[j][i]=mat[i][k]+mat[k][j];
				}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(mat[i][j]>max)
					max=mat[i][j];
		if(max<inf)printf("Case #%d:\n%.4lf\n\n",l+1,max);
		else printf("Case #%d:\nSend Kurdy\n\n",l+1);
	}
	return 0;
}













