#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)



int main()
{
	int n,num[11][11],i,j,k,cs=0,cum[11][11];
	int ans[10];
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,n)
			Foro(j,n)
				scanf("%d",&num[i][j]);
		cum[0][0]=num[0][0];
		for(i=1;i<n;i++)
			cum[0][i]=cum[0][i-1]+num[0][i],cum[i][0]=cum[i-1][0]+num[i][0];
		for(i=1;i<n;i++)
			for(j=1;j<n;j++)
				cum[i][j]=cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1]+num[i][j];
		j=0;
		if(n<3)
		{
			printf("Case %d: %d\n",++cs,cum[n-1][n-1]);
			continue;
		}
		if(n%2)
		{
			ans[j]=num[n/2][n/2];
			j++;
			for(k=1;k<(n/2);k++)
			{
				i=n/2+k;
				ans[j]=cum[i][i]-cum[i][i-2*k-1]-cum[i-2*k-1][i]+cum[i-2*k-1][i-2*k-1];
				for(i=0;i<j;i++)
					ans[j]-=ans[i];
				j++;
			}
			ans[j]=cum[n-1][n-1];
			for(i=0;i<j;i++)
				ans[j]-=ans[i];
			j++;
		}
		else
		{
			ans[j]=cum[n/2][n/2]-cum[n/2][n/2-2]-cum[n/2-2][n/2]+cum[n/2-2][n/2-2];
			j++;
			for(k=1;k<(n/2-1);k++)
			{
				i=n/2+k;
				ans[j]=cum[i][i]-cum[i-2*k-2][i]-cum[i][i-2*k-2]+cum[i-2*k-2][i-2*k-2];
				for(i=0;i<j;i++)
					ans[j]-=ans[i];
				j++;
			}
			ans[j]=cum[n-1][n-1];
			for(i=0;i<j;i++)
				ans[j]-=ans[i];
			j++;
		}
		printf("Case %d:",++cs);
		for(i=j-1;i>=0;i--)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
