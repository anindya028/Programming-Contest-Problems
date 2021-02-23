#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

int mat[105][105];

int main()
{
	int n,t,d,mx;
	register int i,j,k;
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				mat[i][j]=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&t);
			for(j=0;j<t;++j)
			{
				scanf("%d",&d);
				mat[i][d]=1;
			}
		}
		for(k=1;k<=n;++k)
			for(i=1;i<=n;++i)
				for(j=1;j<=n;++j)
					if(mat[i][k] && mat[k][j])
						mat[i][j]=1;
		d=1,mx=0;
		for(i=1;i<=n;++i)
		{
			k=0;
			for(j=1;j<=n;++j)
				if(mat[i][j])
					k++;
			if(k>mx)
			{
				mx=k;
				d=i;
			}
		}
		printf("%d\n",d);
	}
	return 0;
}
