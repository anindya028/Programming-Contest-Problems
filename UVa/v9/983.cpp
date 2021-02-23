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

long long mat[1005][1005],cum[1005][1005],blur[1005][1005];

int main()
{
	int n,m,i,j,cs=0,sum;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(cs)
			printf("\n");
		cs++;
		Foro(i,n)
			Foro(j,n)
				scanf("%lld",&mat[i][j]);
		cum[0][0]=mat[0][0];
		for(i=1;i<n;i++)
			cum[i][0]=cum[i-1][0]+mat[i][0],cum[0][i]=cum[0][i-1]+mat[0][i];
		For(i,1,n)
			For(j,1,n)
				cum[i][j]=cum[i][j-1]+cum[i-1][j]-cum[i-1][j-1]+mat[i][j];
		blur[0][0]=cum[m-1][m-1];
		for(i=1;i<n-m+1;i++)
			blur[i][0]=cum[i+m-1][m-1]-cum[i-1][m-1];
		for(i=1;i<n-m+1;i++)
			blur[0][i]=cum[m-1][i+m-1]-cum[m-1][i-1];
		for(i=1;i<n-m+1;i++)
			for(j=1;j<n-m+1;j++)
				blur[i][j]=cum[i+m-1][j+m-1]-cum[i+m-1][j-1]-cum[i-1][j+m-1]+cum[i-1][j-1];
		sum=0;
		Foro(i,n-m+1)
			Foro(j,n-m+1)
				sum+=blur[i][j],printf("%lld\n",blur[i][j]);
		printf("%lld\n",sum);
	}
	return 0;
}
