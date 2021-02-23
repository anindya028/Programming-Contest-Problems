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

int dp[5][4][5][4][8][8][8][8];

int make(int colst,int lenst,int col,int len,int a,int b,int c,int d)
{
	int i,ans=0;
	if(col && len)
	{
		if(!(a+b+c))
		{
			if(lenst!=d && colst!=4 && col!=4 && len!=d && d<=3)
				return 1;
			else return 0;
		}
		if(!(b+c+d))
		{
			if(lenst!=a && colst!=1 && col!=1 && len!=a && a<=3)
				return 1;
			else return 0;
		}
		if(!(c+d+a))
		{
			if(lenst!=b && colst!=2 && col!=2 && len!=b && b<=3)
				return 1;
			else return 0;
		}
		if(!(d+a+b))
		{
			if(lenst!=c && colst!=3 && col!=3 && len!=c && c<=3)
				return 1;
			else return 0;
		}
	}
	if(dp[colst][lenst][col][len][a][b][c][d]!=-1)
		return dp[colst][lenst][col][len][a][b][c][d];
	for(i=1;i<=3 && i<=a && col!=1;i++)
	{
		if(i==len)
			continue;
		if(!col && !len)
			ans+=make(1,i,1,i,a-i,b,c,d);
		else 
			ans+=make(colst,lenst,1,i,a-i,b,c,d);
	}
	for(i=1;i<=b && i<=3 && col!=2;i++)
	{
		if(i==len)
			continue;
		if(!col && !len)
			ans+=make(2,i,2,i,a,b-i,c,d);
		else
			ans+=make(colst,lenst,2,i,a,b-i,c,d);
	}
	for(i=1;i<=c && i<=3 && col!=3;i++)
	{
		if(i==len)
			continue;
		if(!col && !len)
			ans+=make(3,i,3,i,a,b,c-i,d);
		else
			ans+=make(colst,lenst,3,i,a,b,c-i,d);
	}
	for(i=1;i<=d && i<=3 && col!=4;i++)
	{
		if(i==len)
			continue;
		if(!col && !len)
			ans+=make(4,i,4,i,a,b,c,d-i);
		else
			ans+=make(colst,lenst,4,i,a,b,c,d-i);
	}
	dp[colst][lenst][col][len][a][b][c][d]=ans;
	return ans;
}

int main()
{
	int n,p[4],t,cs,i,j,k,l,m,u,v;
	scanf("%d",&t);
	Foro(u,5)
		Foro(v,4)
			Foro(i,5)
				Foro(j,4)
					Foro(k,8)
						Foro(l,8)
							Foro(m,8)
								Foro(n,8)
									dp[u][v][i][j][k][l][m][n]=-1;
	Foro(cs,t)
	{
		scanf("%d",&n);
		Foro(i,n)
			scanf("%d",&p[i]);
		for(;i<4;i++)
			p[i]=0;
		sort(p,p+4);
		if(!(p[1]+p[2]+p[3]+p[0]))
		{
			printf("1\n");
			continue;
		}
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n",make(0,0,0,0,p[0],p[1],p[2],p[3]));
	}
	return 0;
}
