//DP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
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

char s[5][1005];
int cu[5][1005];
int memo[5][5][5][1005],n;

int calc(int now,int k,int pos)
{
	if(now>k)
	{
		if(k>0)
			return (cu[now][pos]-cu[k-1][pos]);
		else
			return cu[now][pos];
	}
	else
	{
		if(now>0)
			return (cu[k][pos]-cu[now-1][pos]);
		else
			return cu[k][pos];
	}
}

int make(int p,int q,int r,int pos)
{
	int i,j,k,mn=inf,now=0;
	if(pos==(n-1))
		return (s[p][pos]+s[q][pos]+s[r][pos]-3*'0');
	if(memo[p][q][r][pos]!=-1)
		return memo[p][q][r][pos];
	for(i=0;i<q;i++)
	{
		now+=calc(i,p,pos);
		for(j=Max(i,p)+1;j<r;j++)
		{
			now+=calc(j,q,pos);
			for(k=Max(j,q)+1;k<5;k++)
			{
				now+=calc(k,r,pos);
				mn=Min(mn,now+make(i,j,k,pos+1));
				now-=calc(k,r,pos);
			}
			now-=calc(j,q,pos);
		}
		now-=calc(i,p,pos);
	}
	memo[p][q][r][pos]=mn;
	return mn;
}

int main()
{
	int i,j,p,q,r,l,k;
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,5)
			scanf("%s",s[i]);
		p=q=r=-1;
		for(i=0;i<5;i++)
			if(s[i][0]=='@')
			{
				if(p==-1)
					p=i;
				else if(q==-1)
					q=i;
				else
					r=i;
				s[i][0]='0';
			}
		Foro(i,n)
		{
			cu[0][i]=s[0][i]-'0';
			For(j,1,5)
				cu[j][i]=cu[j-1][i]+s[j][i]-'0';
		}
		Foro(i,5)
			Foro(j,5)
				Foro(k,5)
					Foro(l,n+2)
						memo[i][j][k][l]=-1;
		printf("%d\n",make(p,q,r,0));
	}
	return 0;
}