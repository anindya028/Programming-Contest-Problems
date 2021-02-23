/* 
 * File:   4788.cpp
 * Author: User
 *
 * Created on January 31, 2011, 5:59 AM
 */

#include <cstdlib>
#include <stdio.h>
#include<string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define maxn 105

int a[maxn],m[maxn],g[maxn],visited[maxn];
vector<int> adj[maxn];
vector< pii > sub[maxn];

bool comp(pii x,pii y)
{
    return x.second>y.second;
}

pii dfs(int now)
{
    pii ret;

    if(adj[now].size()==1 && visited[adj[now][0]])
    {
        ret.first=Max(a[now],m[now]+g[now]);
        ret.second=Max(0,a[now]-m[now]-g[now]);
        return ret;
    }
    visited[now]=1;
    sub[now].clear();
    int i,u;
    for(i=0;i<adj[now].size();i++)
    {
        u=adj[now][i];
        if(visited[u])
            continue;
        sub[now].push_back(dfs(u));
    }
    sort(sub[now].begin(),sub[now].end(),comp);

    
    ret.first = Max(a[now],m[now]+g[now]);
    ret.second = Max(0,a[now]-m[now]-g[now]);

    for(i=0;i<sub[now].size();i++)
    {
        if(ret.second>sub[now][i].first)
            ret.second = ret.second - sub[now][i].first + sub[now][i].second;
        else
        {
            ret.first += (sub[now][i].first - ret.second);
            ret.second = sub[now][i].second;
        }
    }

    return ret;
}

int main() {

    int n,i,u,v,cs=0;
    while(scanf("%d",&n)==1 && n)
    {
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            scanf("%d%d%d",&a[i],&m[i],&g[i]);
        }
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ret=1<<29;
        //ans=0;

        for(i=1;i<=n;i++)
        {
            memset(visited,0,sizeof(visited));
            visited[i]=1;
            pii got=dfs(i);
            ret=Min(ret,got.first);
        }
        printf("Case %d: %d\n",++cs,ret);
    }
    return 0;
}

