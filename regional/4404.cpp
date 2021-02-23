#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
#define mem(a) memset(a,-1,sizeof(a))

long long dp[16][1<<16];
int p[16][1<<16],n;
vector<int> adj[16];
map<string,int> mm,mw;
map<int,string> bmw;

long long make(int pos,int now)
{
	if(pos==n)
		return 1;
	if(dp[pos][now]!=-1)
		return dp[pos][now];
	dp[pos][now]=0;
	p[pos][now]=-1;
	int i;
	long long t;
	Forc(i,adj[pos])
		if(!(now & 1<<adj[pos][i]))
		{
			t=make(pos+1,now | 1<<adj[pos][i]);
			dp[pos][now]+=t;
			if(t)
			{
				if(p[pos][now]==-1 || bmw[adj[pos][i]]<bmw[p[pos][now]])
					p[pos][now]=adj[pos][i];
			}
		}
	return dp[pos][now];
}
	
int main()
{
	int cs=0,j,i,bs,dbs,t;
	char s[1000],tt[1000];
	string ss,now;
	scanf("%d",&t);
	vector<string> vs;
	long long ans;
	while(t--)
	{
		printf("Case %d:\n",++cs);
		scanf("%d",&n);
		mem(dp);
		mm.clear(),mw.clear(),bmw.clear();
		vs.clear();
		Foro(i,n)
			scanf("%s",s),ss=s,vs.push_back(ss);
		sort(vs.begin(),vs.end());
		Forc(i,vs)
			mm[vs[i]]=i;
		Foro(i,n)
			scanf("%s",s),ss=s,mw[ss]=i,bmw[i]=ss;
		gets(s);
		Foro(i,n)
		{
			gets(s);
			bs=0;
			sscanf(s+bs,"%s%n",tt,&dbs);
			bs+=dbs;
			ss=tt;
			now=ss.substr(0,strlen(tt)-1);
			j=mm[now];
			adj[j].clear();
			while(sscanf(s+bs,"%s%n",tt,&dbs)==1)
				bs+=dbs,ss=tt,adj[j].push_back(mw[ss]);
		}
		ans=make(0,0);
		if(!ans)
		{
			printf("No Way\n");
			continue;
		}
		printf("%lld\n",ans);
		ss="";
		ss+=vs[0];
		ss+=' ';
		i=j=0;
		ss+=bmw[p[i][j]];
		j=j | (1<<p[i][j]);
		i++;
		while(i<n)
		{
			ss+=' ';
			ss+=vs[i];
			ss+=' ';
			ss+=bmw[p[i][j]];
			j=j | (1<<p[i][j]);
			i++;
		}
		printf("%s\n",ss.c_str());
	}
	return 0;
}