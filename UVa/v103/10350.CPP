//Easy DP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define inf 1<<28
#define Min(a,b) (((a)<(b))?(a):(b))

int main()
{
	int mat[20][20],i,j,n,m,k,cur[20],prev[20],ans;	
	char s[100];
	while(scanf("%s",s)==1)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			prev[i]=0;
			cur[i]=inf;
		}
		for(k=1;k<n;k++)
		{
			for(i=0;i<m;i++)
				for(j=0;j<m;j++)
					scanf("%d",&mat[i][j]);
			for(i=0;i<m;i++)
				for(j=0;j<m;j++)
					cur[i]=Min(cur[i],prev[j]+mat[j][i]);
			for(i=0;i<m;i++)
			{
				prev[i]=cur[i];
				cur[i]=inf;
			}
		}
		ans=inf;
		for(i=0;i<m;i++)
			ans=Min(ans,prev[i]);
		printf("%s\n%d\n",s,ans+(n-1)*2);
	}
	return 0;
}
