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
#define Long long long

Long coef[53][53];

int main()
{
	int i,j,n;
	coef[1][0]=0,coef[1][1]=1;
	coef[2][0]=-1,coef[2][1]=0,coef[2][2]=2;
	for(i=3;i<51;i++)
	{
		for(j=1;j<=i;j++)
			coef[i][j]=2*coef[i-1][j-1];
		for(j=0;j<=i;j++)
			coef[i][j]-=coef[i-2][j];
	}
	while(scanf("%d",&n)==1 && n)
	{
		if(n==1)
		{
			printf("Cos(A)\n");
			continue;
		}
		for(i=n;i>=0;i--)
		{
			if(!coef[n][i])
				continue;
			if(i!=n)
			{
				if(coef[n][i]>0)
					printf("+%lld",coef[n][i]);
				else 
					printf("%lld",coef[n][i]);
			}
			else printf("%lld",coef[n][i]);
			if(i==1)
				printf("Cos(A)");
			else if(i>1)
				printf("Cos^%d(A)",i);
		}
		printf("\n");
	}
	return 0;
}
