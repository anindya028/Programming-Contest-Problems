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

#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))

char s[6][6];
int vis[6][6];
int ans,m;

vector<string> word;
string w;

int calc(int n)
{
	if(n<=4)
		return 1;
	if(n==5)
		return 2;
	if(n==6)
		return 3;
	if(n==7)
		return 5;
	return 11;
}

int got;

void dfs(int r,int c,int now)
{
	if(r<0 || c<0 || r>=4 || c>=4 || w[now]!=s[r][c] || vis[r][c])
		return;
	
	
	if(now==(SZ(w)-1))
	{
		got=1;
		return;
	}
	
	vis[r][c]=1;

	int i,j;
	for(i=-1;i<=1;i++)
		for(j=-1;j<=1;j++)
			if(i || j)
				dfs(r+i,c+j,now+1);
	vis[r][c]=0;
}

int main()
{
	int t,cs=0,i,j,k;
	char tt[100];
	string ss;
	scanf("%d",&t);
	Foro(cs,t)
	{
		Foro(i,4)
			scanf("%s",s[i]);
		scanf("%d",&m);
		word.clear();
		Foro(i,m)
			scanf("%s",tt),ss=tt,word.push_back(tt);
		
		ans=0;
		mem(vis,0);
		Forc(i,word)
		{
			w=word[i];
			got=0;
			Foro(j,4)
				Foro(k,4)
				{
				//	mem(vis,0);
					dfs(j,k,0);
					if(got)
						goto done;
				}
done:;
			if(got)
				ans+=calc(SZ(w));
		}
		printf("Score for Boggle game #%d: %d\n",cs+1,ans);
	}
	return 0;
}