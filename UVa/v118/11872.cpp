//team14

#pragma warning(disable:4786)
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<iostream>
#include<sstream>
#include<stack>
#include<utility>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef long long LL;
typedef pair<int,int> PII;

vector<PII> adj[18];

int vis[1<<16][16],memo[1<<16][16],n,cs;

int make2(int now,int pos)
{
    if(now==((1<<n)-1))
        return 1;
    if(vis[now][pos]==cs)
        return memo[now][pos];
    vis[now][pos] = cs;
    memo[now][pos]=0;

//printf(">>%d %d\n", now, pos);
    if( ((now>>pos)&1) == 0 ) return 0;

    int i;
    for(i=0;i<adj[pos].size();i++)
        if(!(now & (1<<adj[pos][i].first)))
            memo[now][pos] |= make2(now | (1<<adj[pos][i].first),adj[pos][i].first);
    return memo[now][pos];
}

int seen[1<<16][16];
double dp[1<<16][16];
double make(int now,int pos)
{
    if(seen[now][pos]==cs)
        return dp[now][pos];
    double &ret=dp[now][pos];
    seen[now][pos]=cs;
    int v=1,i;
    for(i=0;i<adj[pos].size();i++)
        if(!(now & (1<<adj[pos][i].first)))
            if(make2(now | (1<<adj[pos][i].first),adj[pos][i].first))
                v++;
    if(v==1)
    {
        ret=0;
        return 0;
    }
    ret=5.*(1./v);
    for(i=0;i<adj[pos].size();i++)
        if(!(now & (1<<adj[pos][i].first)))
            if(make2(now | (1<<adj[pos][i].first),adj[pos][i].first))
                ret+=(1./v)*(adj[pos][i].second+make(now | 1<<(adj[pos][i].first),adj[pos][i].first));
    ret/=(1.-(1./v));
    return ret;
}

int main(){

    int t,i,u,v,w,m,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        cs++;
        for(i=0;i<n;i++)
            adj[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        printf("Case %d: %.8lf\n",cs,make(1,0));
    }
    return 0;
}
